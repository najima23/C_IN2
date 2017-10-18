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
