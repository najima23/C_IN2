/****************************************************************************************************
*****************************************************************************************************
*** MODUL:          teams.c
*** BESCHREIBUNG:   Stellt die Funktionen f�r die Verwaltung der Teams zur Verf�gung
*** GLOBALE FKT:
*** LOKALE FKT:
****************************************************************************************************
***************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "teams.h"
#include "tools.h"
#include "datastructure.h"

int TeamCounter;
TTeam Teams[MAXTEAMS];

/********************************************************************
 * Funktion:      createTeam
 * Beschreibung:  Erstellt ein Team
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void createTeam(TTeam *Team)
{
   char *title = "Erfassung einer neuen Mannschaft";
   char *Player;
   clearScreen();

   printf("%s\n", title);
   printLine('=', strlen(title));
   printf("\n\n");

   getText("Geben Sie bitte den Namen der Mannschaften ein:\n-> ", 50, 0, &(Team->Name));
   getText("Geben Sie bitte den Namen des Trainers ein:\n-> ", 50, 0, &(Team->Coach));

   Team->Size = 0;
   createPlayer(&Player);
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
void createPlayer(TPlayer *Player)
{
   /* Ausgabe Titel */
   char title[] = "Erfassung der Spieler";
   printf("\n%s\n", title);
   printLine('-', strlen(title));

   getText("\nGeben Sie bitte den Namen des Spielers ein:\n-> ", 50, 0, &(Player->Name));
   clearBuffer();

/*   printf("Geben Sie bitte das Geburtsdatum des Spielers ein:\n-> ");
   scanf("%i", &Birthday);
   clearBuffer;

   printf("Geben Sie bitte die Trikotnr. des Spielers ein:\n-> ");
   scanf("%i", &Number);   // EINE NUMMER IN STRINGFORM?
   clearBuffer();*/

   printf("\n");
//   Goals = 0;     // UNN�TIG, IST SCHON 0

   printf("\n");
   waitForEnter();      // BRAUCHEN WIR GLAUB ICH NICHT MEHR
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
void listOnePlayer(TPlayer *NAME)  // @Franz: da fehlt ein Name =
{

   printf("listOnePlayer\n\n");

   //printf("%s (%d ; * %i)\n",(*ptr).Name, (*ptr).Number, (*ptr).Birthday);

   waitForEnter();
}

/********************************************************************
 * Funktion:      listOneTeam
 * Beschreibung:  Listet ein Team auf
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void listOneTeam()
{
   printf("listOneTeam\n\n");



   waitForEnter();
}


/********************************************************************
 * Funktion:      listTeams
 * Beschreibung:  Listet die Teams auf
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void listTeams()
{
   printf("listTeams\n\n");


   waitForEnter();
}
