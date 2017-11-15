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
void createTeam(struct TTeam *Name, struct TTeam *Coach, TTeam *Size)      // ARGUMENTE ERGEBEN GAR KEINEN SINN. ES SOLLTE NUR EIN ZEIGER AUF DIE STRUKTUR ÜBERGEBEN WERDEN. WENN ÜBERHAUPT
{
   char title[] = "Erfassung einer neuen Mannschaft";    // WIESO ARRAY-SCHREIBWEISE?
   clearScreen();

   printf("%s\n", title);
   printLine('=', strlen(title));
   printf("\n\n");


   // GEDANKLICH ERSTMAL RICHTIG, ABER NOCH VIELE FEHLER
   printf("Geben Sie bitte den Namen der Mannschaften ein:\n-> ");
   scanf("%s", &Name);        // DIE EINGABE SOLL ÜBER DIE FUNKTION getText() ERFOLGEN
   clearBuffer();

   printf("Geben Sie bitte den Namen des Trainers ein:\n-> ");
   scanf("%s", &Coach);       // DIE EINGABE SOLL ÜBER DIE FUNKTION getText() ERFOLGEN
   clearBuffer;

   Size = 0;                  // FALSCHER ZUGRIFF
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
void createPlayer(TPlayer *Name, TPlayer *Birthday, TPlayer *Number, TPlayer *Goals, TTeam *Size) // ARGUMENTE ERGEBEN GAR KEINEN SINN. ES SOLLTE NUR EIN ZEIGER AUF DIE STRUKTUR ÜBERGEBEN WERDEN.
{
   char title[] = "Erfassung der Spieler";

   printf("\n%s\n", title);
   printLine('-', strlen(title));

   do
   {
      // AUCH HIER SOLL ALLES ÜBER SEPERATE FUNKTIONEN ZUR EINGABE ABLAUFEN. AN SICH IST DER ABLAUF ABER RICHTIG, SOLANGE NICHT KOMMENTIERT
      printf("\n");  // WOZU DAS?
      printf("Geben Sie bitte den Namen des Spielers ein:\n-> ");
      scanf("%s", &Name);
      clearBuffer();

      printf("Geben Sie bitte das Geburtsdatum des Spielers ein:\n-> ");
      scanf("%s", &Birthday);
      clearBuffer;

      printf("Geben Sie bitte die Trikotnr. des Spielers ein:\n-> ");
      scanf("%s", &Number);   // EINE NUMMER IN STRINGFORM?
      clearBuffer();

      printf("\n");
      Goals = 0;     // UNNÖTIG, IST SCHON 0
      Size++;     // DEN ZEIGER WEITERSCHIEBEN? AUßERDEM GEHÖRT DAS NICHT IN DIESE FUNKTION

   } while(askYesOrNo("Moechten Sie einen weiteren Spieler eingeben (j/n)?"));      // DIE FUNKTION SOLL NUR EINEN SPIELER ERSTELEN, MEHR NICHT. DIE SCHLEIFE MUSS WOANDERS HIN
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
void listOnePlayer(struct TPlayer *ptr)  // strukt UNNÖTIG, DARUM HABEN WIR JA TPEDEF GEMACHT, *ptr ALS NAME UNGEEIGNET
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
