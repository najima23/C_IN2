#ifndef DATATIME_H_INCLUDED
   #define DATATIME_H_INCLUDED

   short isLeapYear(int);                       // Überprüft, ob es sich um ein Schaltjahr handel
   short isDateValid(TDate);                    // Überprüft ein übergebenes Datum
   short getDateFromString(char *, TDate *);    // Extrahiert aus einem String ein Datum und speichert es in eine Struktur
   short isTimeValid(TTime);                    // Überprüft eine übergebene Zeit
   short getTimeFromString(char *, TTime *);    // Extrahiert aus einem String eine Zeit und speichert sie in eine Struktur

#endif
