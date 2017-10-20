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
int isLeapYear (int year)
{
   if ( year%400 == 0)
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
 * Beschreibung:  Überprüft, ob das als Argument übergebene Datum
 *                gültig ist
 * Paramater:     Eine Struktur, die das Datum beinhaltet
 * Ergebnis:      1, wenn das Datum gültig ist
 *                0, wenn nicht
 *******************************************************************/
int isDateValid (TDate Date)
{
   int daysPerMonth = 0;

   switch (Date.Month)
   {
      case 1:
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
   if ((daysPerMonth == 28) && (isLeapYear(Date.Year)))
      daysPerMonth++;

   if (Date.Day >= 1 && Date.Day <= daysPerMonth &&
       Date.Year >= 1900 && Date.Year <= 2199)
      return 1;
   else
      return 0;
}

/********************************************************************
 * Funktion:      isTimeValid
 * Beschreibung:  Überprüft, ob die als Argument übergebene Zeit
 *                gültig ist
 * Paramater:     Eine Struktur, die die Zeit beinhaltet
 * Ergebnis:      1, wenn die Zeit gültig ist
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

// ***************************************************************************************************
// ***************************************************************************************************
// ************************* PP (Peters Programm) ****************************************************
// ***************************************************************************************************
// ***************************************************************************************************

/********************************************************************
 * Funktion:      getDateFromString
 * Beschreibung:  Ein in Stringform eingegebenes Datum wird in Int
 *                umgewandelt, überprüft und wenn korrekt in eine
 *                Struktur gespeichert.
 * Paramater:     - Der String, der das Datum enthalten soll
 *                - Zeiger auf eine Struktur, in die das Datum
 *                  gespeichert werden soll
 * Ergebnis:      1, wenn der String ein gültiges Datum enthielt
 *                0, wenn nicht
 *******************************************************************/
short getDateFromString(char *input, TDate *date)
{
   char  *pDay = input,
         *pMonth = NULL,
         *pYear = NULL,
         *pSearch = input;

   TDate toValid;

   while (*pSearch)                                   // String nach Punkten durchsuchen und Pointer
   {                                                  // für Monat und Jahr hinter die Punkte setzen
      if ( *pSearch == '.')
      {
         if (!pMonth)
            pMonth = pSearch+1;
         else
         {
            pYear = pSearch+1;
            break;                                    // Wenn Pointer für Jahr gesetzt: Suchschleife verlassen
         }
      }

      pSearch++;
   }

   if (!(*pSearch))                                   // Wenn die Suchschleife bis zum Ende gelaufen ist:
      return 0;                                       // Funktion beenden, Eingabe des Datum ist ungültig

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
 *                umgewandelt, überprüft und wenn korrekt in eine
 *                Struktur gespeichert.
 * Paramater:     - Der String, der die Zeit enthalten soll
 *                - Zeiger auf eine Struktur, in die die Zeit
 *                  gespeichert werden soll
 * Ergebnis:      1, wenn der String eine gültige Zeit enthielt
 *                0, wenn nicht
 *******************************************************************/
short getTimeFromString(char *input, TTime *time)
{
   char  *pHour = input,
         *pMinute = NULL,
         *pSecond = NULL,
         *pSearch = input;

   TTime toValid;

   while (*pSearch)                                   // String nach Doppelpunkten durchsuchen und Pointer
   {                                                  // für Minute und Sekunde hinter die Doppelpunkte setzen
      if ( *pSearch == ':')
      {
         if (pMinute == NULL)
            pMinute = pSearch+1;
         else
         {
            pSecond = pSearch+1;
            break;                                    // Wenn Pointer für Sekunde gesetzt: Suchschleife verlassen
         }
      }

      pSearch++;
   }

   toValid.Hour = atoi(pHour);                        // Zeit in die -Validierungs-Struktur einspeichern

   if (!pMinute)                                      // Falls keine Minute und/oder Sekunde eingegeben: 0 setzen
      toValid.Minute = 0;
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
