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

int isDateValid (TDate Date)
{
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
