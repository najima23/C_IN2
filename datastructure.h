#ifndef DATASTRUCTURE_H_INCLUDED
   #define DATASTRUCTURE_H_INCLUDED
   
   
   
   #define MAXPLAYER 23
   #define MAXTEAMS  10

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

   typedef struct       // Struktur, um Spielerdaten abzuspeichern
   {
      char  *Name;
      TDate *Birthday;
      int    Number;
      int    Goals;
   } TPlayer;

   typedef struct       // Struktur, um Teamdaten abzuspeichern
   {
      char     *Name;
      char     *Coach;
      int       Size;
      TPlayer   Player[MAXPLAYER];
   } TTeam;


#endif
