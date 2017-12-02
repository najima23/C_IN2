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

void loadTeam(char *, FILE *);
void loadPlayer(char *tmp, FILE *fp);

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
               loadTeam(tmp, fp);
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

void loadTeam(char *tmp, FILE *fp)
{
   char *Zeile;
   int len = 0;
   do
   {
      Zeile = tmp;
      fgets(tmp, 100, fp);
      while((*Zeile == ' ') || (*Zeile == 9))
         Zeile++;
      if(strncmp(Zeile, "<Player>", 8) == 0)
         loadPlayer(tmp, fp);

      /* Ausgabe Manschaftsname */
      if(strncmp(Zeile, "<Name>", 6) == 0)
      {
         do
         {
            printf("Manschaftsname: %s", Zeile +6);
            len = strlen(Zeile +6)-3;
         } while(strncmp(Zeile + len, "</Name>", 7) != 0);
      }

      /* Ausgabe Trainername */
      if(strncmp(Zeile, "<Trainer>", 9) == 0)
      {
         do
         {
            printf("Trainername: %s", Zeile +9);
            len = strlen(Zeile +9)-3;
         } while(strncmp(Zeile + len, "</Trainer>", 10) != 0);
      }
   } while(strncmp(Zeile, "</Team>", 7) !=  0);
}

void loadPlayer(char *tmp, FILE *fp)
{
   char *Zeile;
   int len = 0;
   do
   {
      Zeile = tmp;
      fgets(tmp, 100, fp);
      while((*Zeile == ' ') || (*Zeile == 9))
         Zeile++;
      if(strncmp(Zeile, "</Player>", 9) != 0)
//         printf("%s", Zeile);

      /* Ausgabe Spielername */
      if(strncmp(Zeile, "<Name>", 6) == 0)
      {
         do
         {
            printf("Spielername: %s", Zeile + 6);
            len = strlen(Zeile +6)-3;
         } while(strncmp(Zeile + len, "</Name>", 7) != 0);
      }

      /* Ausgabe Geburtstag */
      if(strncmp(Zeile, "<Birthday>", 10) == 0)
      {
         do
         {
            printf("Geburtstag: %s", Zeile + 10);
            len = strlen(Zeile + 10)-3;
         } while(strncmp(Zeile + len, "</Birthday>", 11) != 0);
      }

      /* Ausgabe Trikotnummer */
      if(strncmp(Zeile, "<TricotNr>", 10) == 0)
      {
         do
         {
            printf("TrikoNr.: %s", Zeile + 10);
            len = strlen(Zeile + 10)-3;
         } while(strncmp(Zeile + len, "</TricotNr>", 11) != 0);
      }

      /* Ausgabe Tore */
      if(strncmp(Zeile, "<Goals>", 7) == 0)
      {
         do
         {
            printf("Tore: %s", Zeile + 7);
            len = strlen(Zeile + 7)-3;
         } while(strncmp(Zeile + len, "</Goals>", 8) != 0);
      }
   } while(strncmp(Zeile, "</Player>", 9) != 0);
}

void saveTeam()
{

}

void savePlayer()
{

}
