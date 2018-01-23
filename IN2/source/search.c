/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           search.c
*** BESCHREIBUNG:    Dieses Modul ist beinhaltet zum Einen die Hash-Funktion (z.B. Divisionsrest)
***                  und zum Anderen die eigentliche Suchfunktion
*** GLOBALE FKT:     calcDivisionsrest
***                  search
*** LOKALE FKT:      -/-
*****************************************************************************************************
****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "sort.h"
#include "tools.h"
#include "list.h"


int calcDivRest(TPlayer *P)
{
    int sum = 0;
    char *tmp = P->Name;
    while(*tmp)
    {
        sum += toUpper(*tmp);       // toupper in ctype.h -> klein in Großbuchstaben
        tmp++;
    }
    return(sum % MAXINDEX);
}

TListElement* linearSearch(THashTableElement *Index, char *Input)
{
   TListElement *tmp = Index->First;
   char Name[31];

   if (!tmp)
      return NULL;
   strcpy (Name, tmp->Player->Name);
   while (compareText(Name, Input))
      {
      if (tmp->Next == NULL)
         return NULL;
      tmp = tmp->Next;
      strcpy (Name, tmp->Player->Name);
      }

   return tmp;
}


