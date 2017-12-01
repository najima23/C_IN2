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

void loadTeam(char *, char *, FILE *);
void loadPlayer(char *Zeile, char *tmp, FILE *fp);

int load(char *Datei)
{
   FILE *fp;      // fp = filePointer
   char tmp[101];
   char *Zeile;

   fp = fopen(Datei, "rt");
   if (fp == NULL)
   {
      printf("Datei konnte nicht gelesen werden!");
      return 0;
   }
   else
   {
      do
      {
         while((fgets(tmp, 100, fp)) != NULL)
         {
            Zeile = tmp;
            while((*Zeile == ' ') || (*Zeile == 9))
               Zeile++;
            if(strncmp(Zeile, "<Team>", 6) == 0)
            {
               printf("%s", Zeile);
               fgets(tmp, 100, fp);
               loadTeam(Zeile, tmp, fp);
            }
         }
      } while(strncmp(Zeile, "</Daten>", 8) != 0);
      fclose(fp);
   }
   waitForEnter();
   return 0;
}

void save(TTeam *Player)
{

}

void loadTeam(char *Zeile, char *tmp, FILE *fp)
{
   do
   {
      while((*Zeile == ' ') || (*Zeile == 9))
         Zeile++;
      if(strncmp(Zeile, "<Player>", 8) == 0)
      {
         printf("%s", Zeile);
         fgets(tmp, 100, fp);
         loadPlayer(Zeile, tmp, fp);
      }
      printf("%s", Zeile);
      fgets(tmp, 100, fp);
   } while(strncmp(Zeile, "</Team>", 7) != 0);
   printf("%s", Zeile);
}

void loadPlayer(char *Zeile, char *tmp, FILE *fp)
{
   do
   {
      printf("%s", Zeile);
      fgets(tmp, 100, fp);
   } while(strncmp(Zeile, "</Player>", 9) != 0);
}

void saveTeam()
{

}

void savePlayer()
{

}
