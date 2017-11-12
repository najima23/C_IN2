/****************************************************************************************************
*****************************************************************************************************
*** MODUL:          datetime.c
*** BESCHREIBUNG:   Stellt Funktionen für die Eingabe von Datum und Uhrzeit zur Verfügung
*** GLOBALE FKT:    getDateFromString
*** LOKALE FKT:     isLeapYear
***                 isDateValid
*****************************************************************************************************
****************************************************************************************************/

#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"

/********************************************************************
 * Funktion:      isLeapYear
 * Beschreibung:  Überprüft, ob es sich um das als Argument übergebene Jahr um
 *                ein Schaltjahr handel
 * Paramater:     Das Jahr, das überprüft werden soll
 * Ergebnis:      1, wenn es sich um ein Schaltjahr handel
 *                0, wenn nicht
 *******************************************************************/
short isLeapYear (int year)
{
   if ( year%400 == 0)              // Wenn sich das Jahr durch 400 oder 4, aber nicht durch 100 teilen laesst: Schaltjahr
      return 1;
   else if ( year%100 == 0)
      return 0;
   else if ( year%4 == 0 )
      return 1;
   else
      return 0;
}

/********************************************************************
 * Funktion:      isDateValid
 * Beschreibung:  Ueberprueft, ob das als Argument uebergebene Datum
 *                gueltig ist
 * Paramater:     Eine Struktur, die das Datum beinhaltet
 * Ergebnis:      1, wenn das Datum gueltig ist
 *                0, wenn nicht
 *******************************************************************/
short isDateValid (TDate Date)
{
   int daysPerMonth = 0;      // Anzahl der Tage, die ein Monat hat

   switch (Date.Month)                             // Feststellen, wie viele Tage der eingegebene Monat hat
   {                                               // und Feststellen, ob der eingegebene Monat korrekt ist
      case 1:                                      // Evtl auch mit ENUM?????
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12: daysPerMonth = 31; break;
      case 4:
      case 6:
      case 9:
      case 11: daysPerMonth = 30; break;
      case 2: daysPerMonth = 28; break;
      default: return 0;
   }
   if ((daysPerMonth == 28) && (isLeapYear(Date.Year)))     // Wenn Schaltjahr, dann Februar 29 Tage
      daysPerMonth++;

   if (Date.Day >= 1 && Date.Day <= daysPerMonth &&         // Sind Jahr und Tag korrekt?
       Date.Year >= 1900 && Date.Year <= 2199)
      return 1;
   else
      return 0;
}

/********************************************************************
 * Funktion:      getDateFromString
 * Beschreibung:  Ein in Stringform eingegebenes Datum wird in Int
 *                umgewandelt, ueberprueft und wenn korrekt in eine
 *                Struktur gespeichert.
 * Paramater:     - Der String, der das Datum enthalten soll
 *                - Zeiger auf eine Struktur, in die das Datum
 *                  gespeichert werden soll
 * Ergebnis:      1, wenn der String ein gueltiges Datum enthielt
 *                0, wenn nicht
 *******************************************************************/
short getDateFromString(char *input, TDate *date)
{
   char  *pDay = input,       // Zeiger fuer Tageszahl
         *pMonth = NULL,      // Zeiger fuer Monatszahl
         *pYear = NULL,       // Zeiger fuer Jahreszahl
         *pSearch = input;    // Suchzeiger
   TDate toValid;             // Struktur zum Validieren des Datums

   while (*pSearch)                                   // String nach Punkten durchsuchen und Pointer
   {                                                  // fuer Monat und Jahr hinter die Punkte setzen
      if ( *pSearch == '.')
      {
         if (!pMonth)
            pMonth = pSearch+1;
         else
         {
            pYear = pSearch+1;
            break;                                    // Wenn Pointer fuer Jahr gesetzt: Suchschleife verlassen
         }
      }

      pSearch++;
   }

   if (!pYear)                                        // Wenn die Jahreszeiger nicht gesetzt:
      return 0;                                       // Funktion beenden, Eingabe des Datum ist ungueltig

   toValid.Day = atoi(pDay);                          // Datum in die Validierungs-Struktur einspeichern
   toValid.Month = atoi(pMonth);
   toValid.Year = atoi(pYear);

   if (isDateValid(toValid))                          // Wenn das eingegebene Datum korrekt ist,
   {                                                  // Validierungs-Struktur in Datumstruktur kopieren
      date->Day = toValid.Day;                        // und die Funktion mit 1 beenden
      date->Month = toValid.Month;
      date->Year = toValid.Year;
      return 1;
   }
   else
      return 0;                                       // Ansonsten die Funktion mit 0 beenden
}
