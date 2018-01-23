#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

   int insertInDVList(TTeam *);
   TTeam *removeFromDVList(TTeam *);
   void freeOneTeam(TTeam *);
   void freeOnePlayer(TPlayer *);
   void appendInEVList(THashTableElement *, TTeam *, TPlayer *);
   int getRest (char *);
   int removefromEVList(THashTableElement *, TPlayer *);

#endif
