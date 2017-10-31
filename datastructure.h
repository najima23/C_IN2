#ifndef DATASTRUCTURE_H_INCLUDED
   #define DATASTRUCTURE_H_INCLUDED

   typedef struct       // Struktur, um ein Datum abzuspeichern
   {
      int Day;
      int Month;
      int Year;
   } TDate;

   typedef struct       // Struktur, um eine Zeit abzuspeichern
   {
      int Hour;
      int Minute;
      int Second;
   } TTime;

   typedef struct
   {
       char *SName;
       int *TDate;
       int TrikotNummer;
       int Tore;
   }

#endif
