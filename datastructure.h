#ifndef DATASTRUCTURE_H_INCLUDED
   #define DATASTRUCTURE_H_INCLUDED
   #define MAXPLAYER 23
   #define MAXTEAMS 10

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

   typedef struct       // Struktur, um
   {
      char *playerName;
      int birthDay;
      int shirtNumber;
      int shotGoals;
   } TPlayer;

   typedef struct       // Struktur, um
   {
      char *teamName;
      char *trainerName;
      int numberOfPlayers;
      int TPlayer[MAXPLAYER];
   } TTeam;

#endif
