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

   typedef struct       // Struktur, um Spielerdaten abzuspeichern
   {
      char  *Name;
      TDate *Birthday;
      int    *Number;   // WIESO HABT IHR HIER AUF EINMAL ZEIGER DRAUS GEMACHT???
      int    *Goals;    // WIESO HABT IHR HIER AUF EINMAL ZEIGER DRAUS GEMACHT???
   } TPlayer;

   typedef struct       // Struktur, um Teamdaten abzuspeichern
   {
      char     *Name;
      char     *Coach;
      int      *Size;      // WIESO HABT IHR HIER AUF EINMAL ZEIGER DRAUS GEMACHT???
      TPlayer  Player[MAXPLAYER];
   } TTeam;


    extern int TeamCounter;         // Definition in teams.c
    extern TTeam Teams[];

#endif
