/****************************************************************************************************
*****************************************************************************************************
*** MODUL:          teams.c
*** BESCHREIBUNG:   Stellt die Funktionen für die Verwaltung der Teams zur Verfügung
*** GLOBALE FKT:
*** LOKALE FKT:
****************************************************************************************************
***************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "teams.h"
#include "tools.h"
#include "datastructure.h"

int TeamCounter = 0;
TTeam Teams[MAXTEAMS];

/********************************************************************
 * Funktion:      createTeam
 * Beschreibung:  Erstellt ein Team
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void createTeam()
{
   TTeam *Team = Teams + TeamCounter;
   char *title = "Erfassung einer neuen Mannschaft";
   clearScreen();

   printf("%s\n", title);
   printLine('=', strlen(title));
   printf("\n\n");

   getText("Geben Sie bitte den Namen der Mannschaften ein:\n-> ", 50, 0, &(Team->Name)); //
   getText("Geben Sie bitte den Namen des Trainers ein:\n-> ", 50, 0, &(Team->Coach));

   Team->Size = 0;

   do
   {
      createPlayer(Team->Player + Team->Size);
      (Team->Size)++;
   } while (askYesOrNo("\nMoechten sie einen weiteren Spieler eingeben (j/n)? "));
   TeamCounter++;
}

/********************************************************************
 * Funktion:      deleteTeam
 * Beschreibung:  Loescht ein Team
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void deleteTeam()
{
   printf("deleteTeam\n\n");
   waitForEnter();
}

/********************************************************************
 * Funktion:      createPlayer
 * Beschreibung:  Eingabe eines Spielers
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void createPlayer(TPlayer *Player, TTeam *Team) //Kann man hier den gleichen Pointer nehmen wie bei createTeam?
{
   /* Ausgabe Titel */
   char title[] = "Erfassung der Spieler";
   printf("\n%s\n", title);
   printLine('-', strlen(title));

   getText("\nGeben Sie bitte den Namen des Spielers ein:\n-> ", 50, 0, &(Player->Name));
   getNumber("\nGeben Sie bitte das Geburtsdatum des Spielers ein:\n-> ", &(Player->Number), 1, 99);
   getNumber("\nGeben Sie bitte die Trikotnr. des Spielers ein:\n-> ", &(Player->Number), 1, 99);
   Player->Goals = 0;
   Team->Size++;

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
void searchPlayer()
{
   printf("searchPlayer\n\n");
   waitForEnter();
}

/********************************************************************
 * Funktion:      sortTeams
 * Beschreibung:  Sortiert die Teams
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void sortTeams()
{
   printf("sortTeams\n\n");
   waitForEnter();
}

/********************************************************************
 * Funktion:      listOnePlayer
 * Beschreibung:  Listet einen Spieler auf
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void listOnePlayer(TPlayer *Player)
{
   printf("%s (%i ; ", Player->Name, Player->Number);
//   printDate(Player->Birthday);
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

   printf("\n\nName             : %s", Team->Name);
   printf("Trainer            : %s", Team->Coach);
   printf("Anzahl der Spieler : %i", Team->Size);

   for(i = 0; i < (Team->Size); i++)
   {
      listOnePlayer((Team->Player) + i);
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
   int i;

   if(!TeamCounter)
      printf("Sie haben bis jetzt kein Team eingegeben.\n");
   else
   {
      char title[] = "Liste der Mannschaften";
      printf("\n%s\n", title);
      printLine('-', strlen(title));

      for(i = 0; i < TeamCounter; i++)
      {
         listOneTeam(Teams + i);
      }
   }
}
