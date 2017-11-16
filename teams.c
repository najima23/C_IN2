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
   TeamCounter++;
   do
   {
      createPlayer(&Player);
   } while (askYesOrNo("\nMoechten sie einen weiteren Spieler eingeben (j/n)? "));
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
<<<<<<< HEAD
//<<<<<<< HEAD
   getNumber("\nGeben Sie bitte das Geburtsdatum des Spielers ein:\n-> ", &(Player->Number), 1, 99);
   getNumber("\nGeben Sie bitte die Trikotnr. des Spielers ein:\n-> ", &(Player->Number), 1, 99);
   Player->Goals = 0;
   Team->Size++;
//=======
   clearBuffer();

/*   printf("Geben Sie bitte das Geburtsdatum des Spielers ein:\n-> ");
   scanf("%i", &Birthday);
   clearBuffer;

   printf("Geben Sie bitte die Trikotnr. des Spielers ein:\n-> ");
   scanf("%i", &Number);   // EINE NUMMER IN STRINGFORM?
   clearBuffer();*/

   printf("\n");
//   Goals = 0;     // UNNÖTIG, IST SCHON 0

   printf("\n");
   waitForEnter();      // BRAUCHEN WIR GLAUB ICH NICHT MEHR
//>>>>>>> 9106cf841e94dbb607607e97de936dc61ae89c55
=======

   getNumber("\nGeben Sie bitte das Geburtsdatum des Spielers ein:\n-> ", &(Player->Number), 1, 99);
   getNumber("\nGeben Sie bitte die Trikotnr. des Spielers ein:\n-> ", &(Player->Number), 1, 99);
   Player->Goals = 0;
>>>>>>> ac10fad1336bd77373d63596e2de8e2992aabf64
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
void listOnePlayer(TPlayer *OnePlayer, TTeam *OneTeam)
{
   printf("%s (%i ; * %i)\n", &(OnePlayer->Name), &(OnePlayer->Number), &(OnePlayer->Birthday));
}

/********************************************************************
 * Funktion:      listOneTeam
 * Beschreibung:  Listet ein Team auf
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
void listOneTeam(TTeam *OneTeam, TPlayer *OnePlayer)
{
   int i = 0;

   while(i <= &(OneTeam->Size))
   {
      listOnePlayer();
      i++;
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
   int i = 0;

   while(i <= TeamCounter)
   {
      listOneTeam();
      i++;
   }
}
