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
void createTeam(struct TTeam *Name, struct TTeam *Coach)
{
   printf("createTeam\n\n");

   printf("\nBitte geben Sie einen Teamnamen ein: ");
   scanf("%c", &TTeam --> Name);
   clearBuffer;

   printf("\nBitte geben Sie den Trainernamen ein: ");
   scanf("%c", &TTeam --> Coach);
   clearBuffer;



   waitForEnter();
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
 * Beschreibung:  Hinzufuegen eines Spielers
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void addPlayer(struct TPlayer *Name, struct TPlayer *Birthday)
{
   printf("addPlayer\n\n");

   do
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
   }while(waitForEnter())
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
