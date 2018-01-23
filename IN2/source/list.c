/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           list.c
*** BESCHREIBUNG:    Verkettete Liste
*** GLOBALE FKT:     insertInDVList
***                  removeFromDVList
***                  freeOneTeam
***                  freeOnePlayer
***                  appendInEVList
*** LOKALE FKT:      compare
*****************************************************************************************************
****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "list.h"
#include "sort.h"
#include "teams.h"


int compare(TTeam *, TTeam *);

/***********************************************************
 * Funktion:      insertInDVList
 * Beschreibung:  zum sortierten Einfügen in die doppelt
 *                verkettete Liste
 * Parameter:     -/-
 * Rueckgabe:     -/-
 ***********************************************************/
int insertInDVList(TTeam *Neu)
{
   TTeam *akt = FirstTeam;

   if(!Neu)
      return 0;

   if(FirstTeam == NULL)
   {
      FirstTeam = LastTeam = Neu;
      return 1;
   }

   if(compare(FirstTeam, Neu) >=0)
   {
      Neu->Next = FirstTeam;
      Neu->Prev = NULL;
      FirstTeam = FirstTeam->Prev = Neu;
      return 1;
   }

   if(compare(LastTeam, Neu) <= 0)
   {
      Neu->Next = NULL;
      Neu->Prev = LastTeam;
      LastTeam = LastTeam->Next = Neu;
      return 1;
   }

   while(akt->Next != NULL)
   {
      if(compare(akt->Next, Neu) >= 0)
      {
         Neu->Next = akt->Next;          // (1.1)
         Neu->Prev = akt;                // (1.2)
         akt->Next->Prev = Neu;          // (1.3)
         akt->Next = Neu;                // (1.4)
         return 1;
      }
      akt = akt->Next;
   }
   return 0;
}

/***********************************************************
 * Funktion:      removeFromDVList
 * Beschreibung:  zum Entfernen aus der doppelt verketteten
 *                Liste
 * Parameter:     -/-
 * Rueckgabe:     -/-
 ***********************************************************/
TTeam *removeFromDVList(TTeam *Del)
{
   TTeam *akt = FirstTeam, *tmp = NULL;
   if(!Del)
      return NULL;
   if(FirstTeam == NULL)
      return NULL;
   if(compare(FirstTeam, Del) == 0)
   {
      if(FirstTeam->Next == NULL)
      {
         tmp = FirstTeam;
         FirstTeam = LastTeam = NULL;
         return tmp;
      }
      FirstTeam->Next->Prev = NULL;           // (2.1)
      tmp = FirstTeam;                        // (2.2)
      FirstTeam = FirstTeam->Next;            // (2.3)
      return tmp;
   }
   if(compare(LastTeam, Del) == 0)
   {
      LastTeam->Prev->Next = NULL;            // (3.)
      tmp = LastTeam;
      LastTeam = LastTeam->Prev;
      return tmp;
   }
   while(akt->Next != NULL)
   {
      if(compare(akt->Next, Del) == 0)
      {
         tmp = akt->Next;                // (4.1)
         tmp->Next->Prev = akt;          // (4.2)
         akt->Next = tmp->Next;          // (4.3)
         return tmp;
      }
      akt = akt->Next;
   }
   return NULL;
}
/***********************************************************
 * Funktion:      compare
 * Beschreibung:
 * Parameter:     -/-
 * Rueckgabe:     -/-
 ***********************************************************/
int compare(TTeam *D1, TTeam *D2)
{
   return(strcmp(D1->Name, D2->Name));
}

/***********************************************************
 * Funktion:      freeOneTeam
 * Beschreibung:
 * Parameter:     -/-
 * Rueckgabe:     -/-
 ***********************************************************/
void freeOneTeam(TTeam *deleteTeam)
{
   int i = 0;

   free(deleteTeam->Name);
   free(deleteTeam->Coach);
   while(i < deleteTeam->Size)
   {
      freeOnePlayer(deleteTeam->Player + i);
      i++;
   }
   free(deleteTeam);
}

/***********************************************************
 * Funktion:      freeOnePlayer
 * Beschreibung:
 * Parameter:     -/-
 * Rueckgabe:     -/-
 ***********************************************************/
void freeOnePlayer(TPlayer *deletePlayer)
{
   free(deletePlayer->Name);
   free(deletePlayer->Birthday);
}

/***********************************************************
 * Funktion:      appendInEVList
 * Beschreibung:  ...
 * Parameter:     -/-
 * Rueckgabe:     -/-
 ***********************************************************/
void appendInEVList(THashTableElement *H, TTeam *T, TPlayer *P)
{
   TListElement *tmp = calloc(1, sizeof(TListElement));
   if(tmp)
   {
      tmp->Player = P;
      tmp->Team = T;
      tmp->Next = NULL;

      if(H->First == NULL)
      {
         H->First = H->Last = tmp;
         return;
      }
      H->Last = H->Last->Next = tmp;
      return;
   }
}

int getRest (char *Name)
{
   int i = 0;
   int Sum = 0;
   int Erg = 0;

   while (*(Name + i))
   {
      Sum += toUpper(*(Name +i));
      i++;
   }
   Erg = Sum % MAXINDEX;

   return Erg;
}

TTeam *removefromDVList (TTeam *Del)
{
   TTeam *akt = FirstTeam;
   TTeam *tmp = NULL;

   if (!Del)
      return NULL;
   if (!FirstTeam)
      return NULL;
   if (!compareTeamNames(FirstTeam, Del))
   {
      if (!FirstTeam->Next)
      {
         tmp = FirstTeam;
         FirstTeam = LastTeam = NULL;
         return tmp;
      }
      FirstTeam->Next->Prev = NULL;
      tmp = FirstTeam;
      FirstTeam = FirstTeam->Next;
      return tmp;
   }
   if (!compareTeamNames(LastTeam, Del))
   {
      tmp = LastTeam;
      LastTeam->Prev->Next = NULL;
      LastTeam = LastTeam->Prev;
      return tmp;
   }
   while (akt->Next)
   {
      if (!compareTeamNames(akt->Next, Del))
      {
         tmp = akt->Next;
         tmp->Next->Prev = akt;
         akt->Next = tmp->Next;
         return tmp;
      }
      akt = akt->Next;
   }
   return NULL;
}

int removefromEVList(THashTableElement *Index, TPlayer *Del)
{
   TListElement *tmp = Index->First;
   TListElement *akt;
   if (!tmp)
      return 0;
   if (!strcmp(tmp->Player->Name, Del->Name))
   {
      if (!tmp->Next)
      {
         Index->First = Index->Last = NULL;
         free(tmp);
         return 1;
      }
      Index->First = tmp->Next;
      free(tmp);
      return 1;
   }
   if (!tmp->Next)
      return 0;
   while (strcmp((tmp->Next->Player->Name), (Del->Name)))
   {
      tmp = tmp->Next;
      if (!tmp->Next)
         return 0;
   }
   if(!strcmp(Index->Last->Player->Name, Del->Name))
   {
      Index->Last = tmp;
      akt = tmp->Next;
      tmp->Next = NULL;
      free(akt);
      return 1;
   }
   akt = tmp->Next->Next;
   free(tmp->Next);
   tmp->Next = akt;
   return 1;
}
