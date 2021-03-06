/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           teams.c
*** BESCHREIBUNG     Stellt die Funktionen für die Verwaltung der Teams zur Verfügung
*** GLOBALE FKT:     createTeam
***                  deleteTeam
***                  addPlayer
***                  deletePlayer
***                  searchPlayer
***                  sortTeams
***                  listTeams
***                  loadFileMenu
*** LOKALE FKT:      createPlayer
***                  listOnePlayer
***                  listOneTeam
****************************************************************************************************
***************************************************************************************************/

#define PATH1  "IN2/teams.xml"
#define PATH2  "IN2/little_teams.xml"
#define PATH3  "IN2/save_teams.xml"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastructure.h"
#include "list.h"
#include "datetime.h"
#include "tools.h"
#include "database.h"
#include "menu.h"
#include "sort.h"
#include "search.h"


int TeamCounter = 0;

THashTableElement PlayerIndex[MAXINDEX];

TTeam *FirstTeam = NULL;
TTeam *LastTeam = NULL;

/********************************************************************
 * Funktion:      createPlayer
 * Beschreibung:  Eingabe eines Spielers
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void createPlayer(TPlayer *Player)
{
   getText("\nGeben Sie bitte den Namen des Spielers ein:\n-> ", 50, 0, &(Player->Name));
   getDate("Geben Sie bitte das Geburtsdatum des Spielers ein:\n-> ", &(Player->Birthday));
   getNumber("Geben Sie bitte die Trikotnr. des Spielers ein (1-99):\n-> ", &(Player->Number), 1, 99);
   Player->Goals = 0;
}

/********************************************************************
 * Funktion:      createTeam
 * Beschreibung:  Erstellt ein Team
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void createTeam()
{
   TTeam *Team = calloc(1, sizeof(TTeam));
   char *title = "Erfassung einer neuen Mannschaft";
   int index_hash;

   clearScreen();

   if(Team)
   {
      printf("%s\n", title);
      printLine('=', strlen(title));
      printf("\n\n");

      getText("Geben Sie bitte den Namen der Mannschaften ein:\n-> ", 50, 0, &(Team->Name)); //
      getText("Geben Sie bitte den Namen des Trainers ein:\n-> ", 50, 1, &(Team->Coach));

      Team->Size = 0;

      /* Erfassung eines Spielers in einer neuen Manschaft */
      title = "Erfassung der Spieler";
      printf("\n%s\n", title);
      printLine('-', strlen(title));

      do
      {
         createPlayer((Team->Player) + (Team->Size));     // Spieler erstellen

         /* for Hash */
         index_hash = calcDivRest(Team->Player + Team->Size);
         appendInEVList(PlayerIndex + index_hash, Team, Team->Player + Team->Size);

         (Team->Size)++;                              // Größe der Manschaft um 1 erhöhen
         printf("\nAnzahl der Spieler in der Mannschaft: %i", (Team->Size)); // Test !! Gibt die Aktuelle Größe der Spieler aus
      } while (askYesOrNo("\nMoechten sie einen weiteren Spieler eingeben (j/n)? "));
      insertInDVList(Team);
      TeamCounter++;
   }
   else
   {
      printf("Die maximale Anzahl an Teams(10) ist erreicht!\n\n");
      waitForEnter();
   }
}

/********************************************************************
 * Funktion:      deleteTeam
 * Beschreibung:  Loescht ein Team
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void deleteTeam()
{
   TTeam *tmp = FirstTeam;
   int   index = 1,
         input = 0,
         i = 0,
         HashIndex;
   char *title = "Lister der Mannschaften";

   do
   {
      clearScreen();

      printf("%s\n", title);
      printLine('=', strlen(title));
      printf("\n\n");

      index = 1;
      while(tmp)
      {
         printf("%02i. %s\n", index, tmp->Name);

         tmp = tmp->Next;
         index++;
      }
      printf("\nWelche Mannschaft moechten Sie loeschen (0 fuer Abbrechen) ?");
      scanf("%i", &input);
      tmp = FirstTeam;
   } while (input >= index);

   if(input == 0)
      return;

   tmp = FirstTeam;
   while(i < input-1)
   {
      tmp = tmp->Next;
      i++;
   }

   for(i = 0; i < tmp->Size; i++)
   {
      HashIndex = getRest((tmp->Player + i)->Name);
      removefromEVList(PlayerIndex + HashIndex, (tmp->Player + i));
   }
   removeFromDVList(tmp);
   freeOneTeam(tmp);
}

/********************************************************************
 * Funktion:      addPlayer
 * Beschreibung:  Hinzufuegen von Spielern
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void addPlayer()
{
   printf("addPlayer\n\n");
   waitForEnter();
}

/********************************************************************
 * Funktion:      deletePlayer
 * Beschreibung:  Loeschen eines Spielers
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void deletePlayer()
{
   printf("deletePlayer\n\n");
   waitForEnter();
}

/********************************************************************
 * Funktion:      searchPlayer
 * Beschreibung:  Suchen eines Spielers
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
TListElement* searchPlayer ()
{
   char Input[31];
   int HashIndex, index = 0;
   TListElement *Ergebnis;

   clearScreen();
   printf("Geben Sie bitte den Namen des gesuchten Spielers ein:\n-> ");
   scanf("%30[^\n]", Input);
   clearBuffer();

   HashIndex = getRest(Input);
   Ergebnis = linearSearch((PlayerIndex + HashIndex), Input);
   if (!Ergebnis)
   {
      printf("\nEs wurde kein Spieler mit dem gesuchten Namen gefunden!\n\n");
      waitForEnter();
      return NULL;
   }
   if(Ergebnis)
   {
      printf("\nSuchergebnis:\n-------------\n\n");
      printf("in der Mannschaft %s:\n", Ergebnis->Team->Name);
      printf("   %02d. %s (%02d; * %02i.%02i.%04i; %d Tore)\n\n", ++index, Ergebnis->Player->Name, Ergebnis->Player->Number, Ergebnis->Player->Birthday->Day, Ergebnis->Player->Birthday->Month, Ergebnis->Player->Birthday->Year, Ergebnis->Player->Goals);
   }
   waitForEnter();
   return Ergebnis;
}

/********************************************************************
 * Funktion:      sortTeams
 * Beschreibung:  Sortiert die Teams
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
int sortTeams()
{
   int input;
   char *menuTitel = "Sortieren";
   char *menuItems[] = {"Spieler nach Namen sortieren",
                        "Spieler nach Geburtsdatum sortieren",
                        "Spieler nach TrikotNr. sortieren",
                        "Spieler nach Anzahl geschossener Tore sortieren",
                        "zurueck zum Hauptmenu"};
   input = getMenu(menuTitel, menuItems, 5);  // Menuauswahl
   TTeam *tmp = FirstTeam;

   switch(input)
   {
      case 1:
         while(tmp)
         {
            QuickSort(tmp, tmp->Player, tmp->Size, cmpName);
            tmp = tmp->Next;
         }
         break;
      case 2:
            while(tmp)
            {
               QuickSort(tmp, tmp->Player, tmp->Size, cmpBirthday);
               tmp = tmp->Next;
            }
         break;
      case 3:
         while(tmp)
         {
            QuickSort(tmp, tmp->Player, tmp->Size, cmpTrikot);
            tmp = tmp->Next;
         }
         break;
      case 4:
         {
            QuickSort(tmp, tmp->Player, tmp->Size, cmpGoals);
            tmp = tmp->Next;
         }
         break;
      case 5:
         return 0;
   }
   return 0;
}

/********************************************************************
 * Funktion:      listOnePlayer
 * Beschreibung:  Listet einen Spieler auf
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void listOnePlayer(TPlayer *Player, int Size)
{
   printf("\n   %02i. %-25s(%02i", Size, Player->Name, Player->Number);
   printDate(Player->Birthday);
   if(Player->Goals == 1)
      printf(";%2i Tor", Player->Goals);
   if(Player->Goals != 1)
      printf(";%2i Tore", Player->Goals  );
   printf(")");
}

/********************************************************************
 * Funktion:      listOneTeam
 * Beschreibung:  Listet ein Team auf
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void listOneTeam(TTeam *Team)
{
   int i;

   printf("\n\nName               : %s", Team->Name);
   if(Team->Coach)
   {
      printf("\nTrainer            : %s", Team->Coach);
   }
   printf("\nAnzahl der Spieler : %i", Team->Size);
   printf("\nSpieler:");

   for(i = 0; i < (Team->Size); i++)
   {
      listOnePlayer((Team->Player) + i, i+1);
   }
}

/********************************************************************
 * Funktion:      listTeams
 * Beschreibung:  Listet die Teams auf
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void listTeams()
{
   TTeam *tmp = FirstTeam;
   TTeam *tmp2 = LastTeam;
   int choice;
   char title[] = "Liste der Mannschaften";
   clearScreen();

   if(TeamCounter == 0)
   {
      printf("%s\n", title);     // Print Header für ListTeams
      printLine('=', strlen(title));
      printf("\n\nAktuell sind keine Mannschaften erstellt worden!\n\n");
   }
   else
   {
      choice = menuDVSortList();          // Menu zum Sortieren der Teams
      clearScreen();

      printf("%s\n", title);              // Print Header für ListTeams
      printLine('=', strlen(title));

      if(choice == 1)                     // Menuauswahl Abwaerts sortieren
      {
         while(tmp)
         {
            listOneTeam(tmp);             // Liste ein Team auf
            tmp = tmp->Next;              // geh zum naechsten Team
         }
      }

      else if(choice == 2)                     // Menuauswahl Abwaerts sortieren
      {
         while(tmp2)
         {
            listOneTeam(tmp2);            // Liste das ein Team von hinten auf
            tmp2 = tmp2->Prev;            // geh ein Team zurueck
         }
      }
   }
   printf("\n\n");
   waitForEnter();
}

/********************************************************************
 * Funktion:      loadFileMenu
 * Beschreibung:  Gibt das Load Untermenu aus
 * Paramater:     -/-
 * Ergebnis:      Auswahl des Untermenus
 *******************************************************************/
int loadFileMenu()
{
   int input;
   char *menuTitel = "Datei Laden";
   char *menuItems[] = {"Datei laden (teams.xml)",
                        "Datei laden (little_teams.xml)",
                        "Datei laden (save_teams.xml)",
                        "zurueck zum Hauptmenu"};

   input = getMenu(menuTitel, menuItems, 4);  // Menuauswahl
   switch(input)
   {
      case 1: load(PATH1);    break;
      case 2: load(PATH2);    break;
      case 3: load(PATH3);    break;
      case 4: return 0;
   }
   return 0;
}

/********************************************************************
 * Funktion:      hashList
 * Beschreibung:  ...
 * Paramater:     -/-
 * Ergebnis:      ...
 *******************************************************************/
 void hashList()
 {
   TListElement *tmp = PlayerIndex->First;
   char title[] = "Hash-Tabelle";
   int i;
   clearScreen();


   /* print Tabellenanfang */
   printf("%s\n", title);
   printLine('=', strlen(title));
   printf("\n\nHashwert | Mannschaft                | Spieler\n"); //10 27 26
   printLine('-', 9); printf("|"); printLine('-', 27); printf("|"); printLine('-', 26);

   for(i = 0; i<MAXINDEX; i++)
   {
      tmp = (PlayerIndex + i)->First;
      while(tmp)
      {
         if(tmp == (PlayerIndex + i)->First)
            printf("\n%8d | %-25s | %-24s", i, tmp->Team->Name, tmp->Player->Name);
         else
            printf("\n         | %-25s | %-24s", tmp->Team->Name, tmp->Player->Name);
         tmp = tmp->Next;
      }
   }
   printf("\n\n");
   waitForEnter();
}
