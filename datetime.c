#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"

/********************************************************************
 * Funktion:      isLeapYear
 * Beschreibung:  �berpr�ft, ob es sich um das als Argument �bergebene Jahr um
 *                ein Schaltjahr handel
 * Paramater:     Das Jahr, das �berpr�ft werden soll
 * Ergebnis:      1, wenn es sich um ein Schaltjahr handel
 *                0, wenn nicht
 *******************************************************************/
int isLeapYear (int year)
{
   if ( year%400 == 0)              // Wenn sich das Jahr durch 400 oder 4, aber nicht durch 100 teilen l�sst: Schaltjahr
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
 * Beschreibung:  �berpr�ft, ob das als Argument �bergebene Datum
 *                g�ltig ist
 * Paramater:     Eine Struktur, die das Datum beinhaltet
 * Ergebnis:      1, wenn das Datum g�ltig ist
 *                0, wenn nicht
 *******************************************************************/
int isDateValid (TDate Date)
{
   int daysPerMonth = 0;

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
 * Funktion:      isTimeValid
 * Beschreibung:  �berpr�ft, ob die als Argument �bergebene Zeit
 *                g�ltig ist
 * Paramater:     Eine Struktur, die die Zeit beinhaltet
 * Ergebnis:      1, wenn die Zeit g�ltig ist
 *                0, wenn nicht
 *******************************************************************/
int isTimeValid (TTime Time)
{
   if (Time.Hour >= 0 && Time.Hour <= 23 &&
       Time.Minute >= 0 && Time.Minute <= 59 &&
       Time.Second >= 0 && Time.Second <= 59)
      return 1;
   else
      return 0;
}

/********************************************************************
 * Funktion:      getDateFromString
 * Beschreibung:  Ein in Stringform eingegebenes Datum wird in Int
 *                umgewandelt, �berpr�ft und wenn korrekt in eine
 *                Struktur gespeichert.
 * Paramater:     - Der String, der das Datum enthalten soll
 *                - Zeiger auf eine Struktur, in die das Datum
 *                  gespeichert werden soll
 * Ergebnis:      1, wenn der String ein g�ltiges Datum enthielt
 *                0, wenn nicht
 *******************************************************************/
short getDateFromString(char *input, TDate *date)
{
   char  *pDay = input,       // Zeiger f�r Tageszahl
         *pMonth = NULL,      // Zeiger f�r Monatszahl
         *pYear = NULL,       // Zeiger f�r Jahreszahl
         *pSearch = input;    // Suchzeiger

   TDate toValid;             // Struktur zum Validieren des Datums

   while (*pSearch)                                   // String nach Punkten durchsuchen und Pointer
   {                                                  // f�r Monat und Jahr hinter die Punkte setzen
      if ( *pSearch == '.')
      {
         if (!pMonth)
            pMonth = pSearch+1;
         else
         {
            pYear = pSearch+1;
            break;                                    // Wenn Pointer f�r Jahr gesetzt: Suchschleife verlassen
         }
      }

      pSearch++;
   }

   if (!pYear)                                        // Wenn die Jahreszeiger nicht gesetzt:
      return 0;                                       // Funktion beenden, Eingabe des Datum ist ung�ltig

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

/********************************************************************
 * Funktion:      getTimeFromString
 * Beschreibung:  Eine in Stringform eingegebene Zeit wird in Int
 *                umgewandelt, �berpr�ft und wenn korrekt in eine
 *                Struktur gespeichert.
 * Paramater:     - Der String, der die Zeit enthalten soll
 *                - Zeiger auf eine Struktur, in die die Zeit
 *                  gespeichert werden soll
 * Ergebnis:      1, wenn der String eine g�ltige Zeit enthielt
 *                0, wenn nicht
 *******************************************************************/
short getTimeFromString(char *input, TTime *time)
{
   char  *pHour = input,         // Zeiger f�r Stunden
         *pMinute = NULL,        // Zeiger f�r Minuten
         *pSecond = NULL,        // Zeiger f�r Sekunden
         *pSearch = input;       // Suchzeiger

   TTime toValid;                // Struktur zum Validieren der Zeit

   while (*pSearch)                                   // String nach Doppelpunkten durchsuchen und Pointer
   {                                                  // f�r Minute und Sekunde hinter die Doppelpunkte setzen
      if ( *pSearch == ':')
      {
         if (!pMinute)
            pMinute = pSearch+1;
         else
         {
            pSecond = pSearch+1;
            break;                                    // Wenn Pointer f�r Sekunde gesetzt: Suchschleife verlassen
         }
      }

      pSearch++;
   }

   if ( *pHour >= '0' && *pHour <= '9' )              // �berpr�fen, ob eine Zahl eingegeben wurde
      toValid.Hour = atoi(pHour);                     // Zeit in die Validierungs-Struktur einspeichern
   else
      return 0;

   if (!pMinute)                                      // Falls keine Minute und/oder Sekunde eingegeben: 0 setzen
      toValid.Minute = 0;                             // Ansonsten eingegebene Daten �bertragen
   else
      toValid.Minute = atoi(pMinute);

   if (!pSecond)
      toValid.Second = 0;
   else
      toValid.Second = atoi(pSecond);

   if (isTimeValid(toValid))                          // Wenn Die eingegebene Zeit korrekt ist,
   {                                                  // Validierungs-Struktur in Zeitstruktur kopieren
      time->Hour = toValid.Hour;                      // und die Funktion mit 1 beenden
      time->Minute = toValid.Minute;
      time->Second = toValid.Second;
      return 1;
   }
   else
      return 0;                                       // Ansonsten die Funktion mit 0 beenden
}
