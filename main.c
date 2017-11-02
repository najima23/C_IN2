/****************************************************************************************************
*****************************************************************************************************
*** MODUL:          main.c
*** BESCHREIBUNG:   Hauptprogramm der Mannschaften-Verwaltung
*****************************************************************************************************
****************************************************************************************************/

#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "teams.h"
#include "menu.h"

void inputDate();
void inputTime();

int main()
{
   int i, choice = 0;
   do
   {
      clearScreen();

      char *Menutitel[1] = {"Mannschaften-Verwaltung V0.2"};

      /* Hauptmenu */
      char *Menu[10] =
      {
         "1. Neue Mannschaften anlegen",
         "2. Spieler hinzufuegen",
         "3. Spieler loeschen",
         "4. Mannschaft loeschen",
         "5. Suchen",
         "6. Sortieren",
         "7. Auflisten",
         "8. Programm beenden",
      };

      /* Ausgabe Menu */
      printf("%s\n", Menutitel[0]);
      printLine('=',28);
      printf("\n\n");
      for(i=0; i<10; i++)
      {
         printf("%s\n", Menu[i]);
      }

      choice = getMenu;

      do
      {
         switch(choice)
         {
            case 1: createTeam(); break;
            case 2: addPlayer(); break;
            case 3: deletePlayer(); break;
            case 4: deleteTeam(); break;
            case 5: searchPlayer(); break;
            case 6: sortTeams(); break;
            case 7: listTeams(); break;
            case 8: return 0;
            default: choice = 0; printf("Bitte waehlen sie ein Menupunkt aus!\n");
         }
      }while (choice > 0 && choice < 8);
   } while (askYesOrNo("Moechten Sie noch einmal (j/n) ? "));
}

/********************************************************************
 * Funktion void inputDate(void)
 *   - Benutzer soll ein Datum eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getDateFromString geparst
 *     und geprueft. Bei gueltigem Datum steht dieses in der Datums-
 *     variable Date.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 *   - wird nur die Eingabetaste gedrueckt, wird die Funktion ohne
 *     weitere Bildschirmausgabe beendet.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
void inputDate()
{
   TDate Date;
   char Input[20];
   int ok = 0;

   do
   {
      printf("Geben Sie bitte ein gueltiges Datum ein: ");
      *Input = '\0';
      scanf("%19[^\n]", Input);
      clearBuffer();
      if (*Input)
         if (getDateFromString(Input, &Date))
         {
            printf("Das Datum %02i.%02i.%04i ist gueltig!\n", Date.Day, Date.Month, Date.Year);
            ok = 1;
         }
         else
            printf("Das eingegebene Datum %s ist ungueltig!\n", Input);
      else
         break;
   } while (!ok);

   printf("\n");
}

/********************************************************************
 * Funktion void inputTime(void)
 *   - Benutzer soll eine Uhrzeit eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getTimeFromString geparst
 *     und geprueft. Bei gueltiger Uhrzeit steht diese in der
 *     Uhrzeitvariable Time.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 *   - wird nur die Eingabetaste gedrueckt, wird die Funktion ohne
 *     weitere Bildschirmausgabe beendet.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
void inputTime()
{
   TTime Time;
   char Input[20];
   int ok = 0;

   do
   {
      printf("Geben Sie bitte eine gueltige Uhrzeit ein: ");
      *Input = '\0';
      scanf("%19[^\n]", Input);
      clearBuffer();
      if (*Input)
         if (getTimeFromString(Input, &Time))
         {
            printf("Die Uhrzeit %02i:%02i:%02i ist gueltig!\n", Time.Hour, Time.Minute, Time.Second);
            ok = 1;
         }
         else
            printf("Die eingegebene Uhrzeit %s ist ungueltig!\n", Input);
      else
         break;
   } while (!ok);

   printf("\n");
}
/********************************************************************
 * Funktion
 *   - Benutzer soll eine Uhrzeit eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getTimeFromString geparst
 *     und geprueft. Bei gueltiger Uhrzeit steht diese in der
 *     Uhrzeitvariable Time.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 *   - wird nur die Eingabetaste gedrueckt, wird die Funktion ohne
 *     weitere Bildschirmausgabe beendet.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/

