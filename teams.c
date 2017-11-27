/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           teams.c
*** BESCHREIBUNG:    Stellt die Funktionen für die Verwaltung der Teams zur Verfügung
*** GLOBALE FKT:     createTeam
***                  deleteTeam
***                  addPlayer
***                  deletePlayer
***                  searchPlayer
***                  sortTeams
***                  listTeams
*** LOKALE FKT:      createPlayer
***                  listOnePlayer
***                  listOneTeam
****************************************************************************************************
***************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"

int TeamCounter = 0;
TTeam Teams[MAXTEAMS];

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
   TTeam *Team = Teams + TeamCounter;     // TTeam = Datentyp // pointer + i // &pointer[i] // Funktion will die Adresse vom Pointer wissen
   char *title = "Erfassung einer neuen Mannschaft";
   clearScreen();

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
      createPlayer((Team->Player) + (Team->Size));     // Spieler erstellen (
      (Team->Size)++;                              // Größe der Manschaft um 1 erhöhen
      printf("\nAnzahl der Spieler in der Mannschaft: %i", (Team->Size)); // Test !! Gibt die Aktuelle Größe der Spieler aus
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
void listOnePlayer(TPlayer *Player, int Size)
{
   printf("\n   %02i. %s (%i", Size, Player->Name, Player->Number);
   printDate(Player->Birthday);
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
   int i;

   clearScreen();
   char title[] = "Liste der Mannschaften";
   printf("%s\n", title);
   printLine('=', strlen(title));

   if(TeamCounter == 0)
      printf("\n\nAktuell sind keine Mannschaften erstellt worden!\n\n");

   else
   {
      for(i = 0; i < TeamCounter; i++)
      {
         listOneTeam(Teams + i);
      }
   }
   printf("\n\n");
   waitForEnter();
}
