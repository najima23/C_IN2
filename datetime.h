#ifndef DATATIME_H_INCLUDED
   #define DATATIME_H_INCLUDED

   short isLeapYear(int);
   short isDateValid(TDate);
   short getDateFromString(char *, TDate *);
   short isTimeValid(TTime);
   short getTimeFromString(char *, TTime *);

#endif
