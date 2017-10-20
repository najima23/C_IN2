#ifndef DATATIME_H_INCLUDED
   #define DATATIME_H_INCLUDED

   int isLeapYear(int);
   int isDateValid(TDate);
   short getDateFromString(char *, TDate *);
   int isTimeValid(TTime);
   short getTimeFromString(char *, TTime *);

#endif
