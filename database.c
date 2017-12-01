/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           database.c
*** BESCHREIBUNG:
*** GLOBALE FKT:     save
***                  load
*** LOKALE FKT:      loadTeam
***                  loadPlayer
***                  saveTeam
***                  savePlayer
*****************************************************************************************************
****************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "database.h"
#include "datastructure.h"
#include "tools.h"

int load(char *Datei)
{
   FILE *fp;      // fp = filePointer
   char tmp[101];
   char *Zeile;

   fp = fopen(Datei, "r");
   if (fp == NULL)
   {
      printf("Datei konnte nicht gelesen werden!");
      return 0;
   }
   else
   {
      while((fgets(tmp, 100, fp)) != NULL)
      {
         Zeile = tmp;
         while((*Zeile == ' ') || (*Zeile == 9))
            Zeile++;
         if(strncmp(Zeile, "<Deten>", 7) == 0)
         {
            printf("Test");
            waitForEnter();
            fclose(fp);
            return 1;
         }
      }
      printf("Keine Daten vorhanden!");
      fclose(fp);
   }
   waitForEnter();
   return 0;
}

void save(TTeam *Player)
{

}

void loadTeam()
{

}

void loadPlayer()
{

}

void saveTeam()
{

}

void savePlayer()
{

}
