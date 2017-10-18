#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"

int isLeapYear (int);
int isDateValid (TDate);
int getDateFromString (char *, TDate *);
int isTimeValid (int);
int getTimeFromString (char *, int);

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

int isDateValid (TDate Date, int isLeapYear())
{
   if ((Date.Year >= 1970) && (Date.Year <=2100))
   {
       if ((Date.Month == 01) || (Date.Month >= 03) && (Date.Month <= 12))
       {
          if ((Date.Day >= 01) && (Date.Day >= 31))
          {
             switch(Date.Month)
             {
                case '01':
                case '03':
                case '05':
                case '07':
                case '08':
                case '10':
                case '12': if (Date.Day == (>= 01) && (<= 31)) return 1; break;
                case '04':
                case '06':
                case '09':
                case '11': if (Date.Day == (>= 01) && (<= 30)) return 1; break;
                default: return 0;
             }

           }

       }
       if (Date.Month == 2) && (isLeapYear = 1) && (Date.Day >= 01) && (Date.Day <= 29)
          return 1;

       if ()Date.Month == 2) && (isLeapYear = 0) && (Date.Day >= 01) && (Date.Day <= 28)
          return 1;

       else
          return 0;
   }

   if ((Date.Day >= 0) && (Date.Day <=31))
      if ((Date.Month >= 1) && (Date.Month <=12))
         if ((Date.Year >= 1900) && (Date.Year <=2199))
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
   char day[] = "0";
   while (*(Input + i) != '.')
   {
      *(day + i) = *(Input + i);
      i++;
   }
   *(day + i) = '\0';
   Date->Day = atoi(day);
}

int isTimeValid (int TTime)
{

}

int getTimeFromString (char* input, int Time)
{

}
