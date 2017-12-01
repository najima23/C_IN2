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
#include "database.h"
#include "datastructure.h"
#include "tools.h"

void load(char *Datei)
{
   FILE *fp;
   int temp = 0;

   fp = fopen(Datei, "r");
   if (fp == NULL)
      printf("Datei konnte nicht gelesen werden!");
   else
   {
      while((temp=fgetc(fp))!=EOF)
      {
         printf("%c", temp);
      }
      fclose(fp);
   }
   waitForEnter();
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
