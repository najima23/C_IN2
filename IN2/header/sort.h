#ifndef SORT_H_INCLUDED
   #define SORT_H_INCLUDED

   void QuickSort(TTeam *, TPlayer *, int, int (*)(TPlayer *, TPlayer *));
   int cmpName(TPlayer *, TPlayer *);
   int cmpBirthday(TPlayer *, TPlayer *);
   int cmpTrikot(TPlayer *, TPlayer *);
   int cmpGoals(TPlayer *, TPlayer *);
   char toUpper(char);
   int compareText (char *, char *);
   int compareTeamNames (TTeam *, TTeam *);


#endif
