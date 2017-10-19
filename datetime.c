#include <stdio.h>                           // WIRD NICHT BENÖTIG
#include <stdlib.h>
#include "datastructure.h"

int isLeapYear (int);                        // UNNÖTIG
int isDateValid (TDate);                     //
int getDateFromString (char *, TDate *);     //
int isTimeValid (int);                       //
int getTimeFromString (char *, int);         //

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

int isDateValid (TDate Date, int isLeapYear())     // EINE FUNKTION ALS ARGUMENT? BTW: WELCHE ARGUMENTE ÜBERGEBEN WERDEN SOLLEN, STEHT IN DER AUFGABENSTELLUNG
{
   if ((Date.Year >= 1970) && (Date.Year <=2100))                                // VERSCHATELUNG IST UNÜBERSICHTLICH. 
   {                                                                             // VERSUCHT EINS NACH DEM ANDEREN ABZUARBEITEN
       if ((Date.Month == 01) || (Date.Month >= 03) && (Date.Month <= 12))
       {
          if ((Date.Day >= 01) && (Date.Day >= 31))   // ALLGEMEINER FEHLER
          {
             switch(Date.Month)
             {
                case '01':                                                       // BEI Date.Month HANDELT ES SICH UM INTEGERWERTE
                case '03':
                case '05':
                case '07':
                case '08':
                case '10':
                case '12': if (Date.Day == (>= 01) && (<= 31)) return 1; break;  // 1. SYNTAKTISCHER FEHLER
                case '04':                                                       // 2. WARUM NOCHMAL DIE ABFRAGE NACH 31 TAGE?
                case '06':                                                       // break WIRD AN DIESER STELLE AUCH NICHT BENÖTIGT
                case '09':
                case '11': if (Date.Day == (>= 01) && (<= 30)) return 1; break;  // DER GLEICHE SYNTAKTISCHE FEHLER WIE OBEN
                default: return 0;
             }

           }

       }
       if (Date.Month == 2) && (isLeapYear = 1) && (Date.Day >= 01) && (Date.Day <= 29)      // WOHER KOMMT DIE VARIABLE isLeapYear?
          return 1;

       if (Date.Month == 2) && (isLeapYear = 0) && (Date.Day >= 01) && (Date.Day <= 28)
          return 1;
       else
          return 0;
   }

   if ((Date.Day >= 0) && (Date.Day <=31))                  // WAREN DIE ABFRAGEN NICHT IRGENDWIE OBEN SCHONMAL?
      if ((Date.Month >= 1) && (Date.Month <=12))           // UND WIEDER GLEICHES THEMA WIE OBEN: ABFRAGEN NACHEINANDER
         if ((Date.Year >= 1900) && (Date.Year <=2199))     // UND NICHT VERSCHACHTELT
            return 1;
         else
            return 0;
      else
         return 0;
   else
      return 0;
}

int getDateFromString (char *Input, TDate *Date)
{
   int i = 0;
   char day[] = "0";             // DAS ARRAY WÄRE IN DIESEM FALLE NUR EIN ELEMENT GROß
   while (*(Input + i) != '.')
   {
      *(day + i) = *(Input + i); // DIE ART UND WEISE, WIE DAS DATUM AUCH DEM STRING GEZOGEN WERDNE SOLLTE
      i++;                       // IST IN DER PRÄSENTATION GUT ERKLÄRT
   }
   *(day + i) = '\0';
   Date->Day = atoi(day);        // DER TAG WIRD SCHON VON DER ÜBERPRÜFUNG IN DIE STRUKTUR GESPEICHERT
}

int isTimeValid (int TTime)
{

}

int getTimeFromString (char* input, int Time)
{

}




// ***************************************************************************************************
// ***************************************************************************************************
// ************************* PP (Peters Programm) ****************************************************
// ***************************************************************************************************
// ***************************************************************************************************





#include "datastructure.h"
#include <stdlib.h>

/********************************************************************
 * Funktion:      isLeapYear
 * Beschreibung:  Überprüft, ob es sich um das als Argument übergebene Jahr um
 *                ein Schaltjahr handel
 * Paramater:     Das Jahr, das überprüft werden soll
 * Ergebnis:      1, wenn es sich um ein Schaltjahr handel
 *                0, wenn nicht
 *******************************************************************/
short isLeapYear(int year)
{
   if (year%400 == 0)
      return 1;
   else if (year%100 == 0)
      return 0;
   else if (year%4 == 0)
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
short isDateValid(TDate date)
{
   short daysPerMonth;

   switch (date.Month)                             // Feststellen, wie viele Tage der eingegebene Monat hat
   {                                               // und Feststellen, ob der eingegebene Monat korrekt ist
      case 1:                                      // Evtl auch mit ENUM?????
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12: daysPerMonth = 31;  break;
      case 4:
      case 6:
      case 9:
      case 11: daysPerMonth = 30;  break;
      case 2:  daysPerMonth = 28;  break;
      default: return 0;
   }
   if ( (daysPerMonth == 28) && isLeapYear(date.Year) )     // Wenn Schaltjahr, dann Februar 29 Tage
      daysPerMonth++;

   if (date.Day > daysPerMonth || date.Day <= 0 ||
       date.Year > 2100 || date.Year < 1970)                // Sind Jahr und Tag korrekt?
      return 0;

   return 1;
}

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
 * Funktion:      isTimeValid
 * Beschreibung:  Überprüft, ob die als Argument übergebene Zeit
 *                gültig ist
 * Paramater:     Eine Struktur, die die Zeit beinhaltet
 * Ergebnis:      1, wenn die Zeit gültig ist
 *                0, wenn nicht
 *******************************************************************/
short isTimeValid(TTime time)
{
   if (time.Hour > 23   || time.Hour < 0   ||
       time.Minute > 59 || time.Minute < 0 ||
       time.Second > 59 || time.Second < 0 )
      return 0;

   return 1;
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




