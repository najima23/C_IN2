/****************************************************************************************************
*****************************************************************************************************
*** MODUL:          teams.c
*** BESCHREIBUNG:   Stellt die Funktionen für die Verwaltung der Teams zur Verfügung
*** GLOBALE FKT:
*** LOKALE FKT:
****************************************************************************************************
***************************************************************************************************/

#include <stdio.h>
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
void createTeam(struct TTeam *Name, struct TTeam *Coach, TTeam *Size)
{
   char title[] = "Erfassung einer neuen Mannschaft";
   clearScreen();

   printf("%s\n", title);
   printLine('=', strlen(title));
   printf("\n\n");

   printf("Geben Sie bitte den Namen der Mannschaften ein:\n-> ");
   scanf("%s", &Name);
   clearBuffer();

   printf("Geben Sie bitte den Namen des Trainers ein:\n-> ");
   scanf("%s", &Coach);
   clearBuffer;

   Size = 0;
   createPlayer();
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
void createPlayer(TPlayer *Name, TPlayer *Birthday, TPlayer *Number, TPlayer *Goals, TTeam *Size)
{
   char title[] = "Erfassung der Spieler";

   printf("\n%s\n", title);
   printLine('-', strlen(title));

   do
   {
      printf("\n");
      printf("Geben Sie bitte den Namen des Spielers ein:\n-> ");
      scanf("%s", &Name);
      clearBuffer();

      printf("Geben Sie bitte das Geburtsdatum des Spielers ein:\n-> ");
      scanf("%s", &Birthday);
      clearBuffer;

      printf("Geben Sie bitte die Trikotnr. des Spielers ein:\n-> ");
      scanf("%s", &Number);
      clearBuffer();

      printf("\n");
      Goals = 0;
      Size++;

   } while(askYesOrNo("Moechten Sie einen weiteren Spieler eingeben (j/n)?"));
   printf("\n");
   waitForEnter();
}


/********************************************************************
 * Funktion:      addPlayer
 * Beschreibung:  Hinzufuegen von Spielern
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void addPlayer(struct TPlayer *Name, struct TPlayer *Birthday)
{
/*  do
   {
      do
      {
         printf("\nBitte geben Sie einen Spielernamen ein: ");
         scanf("%c", &TPlayer --> Name);
         clearBuffer;
      }while(!TPlayer-->Name)

      printf("\nBitte geben Sie das Geburtsdatum des Spielers ein: ");
      scanf("%i", &TPlayer --> Birthday);
      clearBuffer;

      do
      {
         printf("\nBitte geben Sie die Trikotnummer des Spielers ein: ");
         scanf("%i", &TPlayer --> Number);
         clearBuffer;
      }while(!TPlayer-->Number)
   }while(waitForEnter())*/

   printf("addPlayer\n\n");
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
void listOnePlayer(struct TPlayer *ptr)
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
void listOneTeams()
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
