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

void loadTeam(char *);

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
               do
               {
                  printf("%s", Zeile);
                  fgets(tmp, 100, fp);
               } while(strncmp(Zeile, "</Team>", 7) != 0);
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

void loadTeam(char *Zeile)
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
