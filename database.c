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

#include "database.h"

void load()
{
   FILE *fp;
   int temp = 0;

   fp = fopen("teams.xml", "r");
   if (fp == NULL)
      printf("Datei konnte nicht gelesen werden!");
   else
   {
      while((temp=fgetc(fp))!=EOF)
      {
         printf
      }
      fclose(fp);
   }
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
