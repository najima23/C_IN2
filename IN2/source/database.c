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
#define PATH  "IN2/Test.xml"     // Pfad zum Speichern

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "datastructure.h"
#include "tools.h"

TTeam Teams[MAXTEAMS];
void loadTeam(char *, FILE *);
<<<<<<< HEAD
void loadPlayer(char *, FILE *, TTeam *);
=======
void loadPlayer(char *, FILE *);
static void saveTeam(TTeam *, FILE *);
static void savePlayer(TPlayer *, FILE *);

>>>>>>> de077474bae5ee00afbaede37f8d74c06d363bb8

int load(char *Datei)
{
   FILE *fp;      // fp = filePointer
   char tmp[101];
   char *Zeile;

   fp = fopen(Datei, "rt");
   if (fp == NULL)
   {
      printf("\nDatei konnte nicht gelesen werden!\n");
      waitForEnter();
      clearScreen();
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
            if (feof(fp))
               break;
         }
      } while(strncmp(Zeile, "</Daten>", 8) != 0);
      fclose(fp);
   }
   waitForEnter();
   return 0;
}

void loadTeam(char *tmp, FILE *fp)
{
   char *Zeile;
   char tmp2[101];
   int len = 0;
   TTeam *Team = Teams + TeamCounter;

   Team->Name = NULL;
   Team->Coach = NULL;
   Team->Size = 0;
   do
   {
      Zeile = tmp;
      fgets(tmp, 100, fp);
      while((*Zeile == ' ') || (*Zeile == 9))
         Zeile++;
      if(strncmp(Zeile, "<Player>", 8) == 0)
         loadPlayer(tmp, fp, Team);

      /* Ausgabe Manschaftsname */
      if(strncmp(Zeile, "<Name>", 6) == 0)
      {
         len = strlen(Zeile + 6) - 9;           // -9 = -7 für </Name> + -2 fuer /r
         strncpy(tmp2, Zeile + 6, len);
         tmp2[len] = '\0';
         printf("Manschaftsname: %s\n", tmp2);
         Team->Name = calloc(len + 1, sizeof(char));
         if(Team->Name)
            strncpy(Team->Name, Zeile + 6, len);
      }

      /* Ausgabe Trainername */
      if(strncmp(Zeile, "<Trainer>", 9) == 0)
      {
         len = strlen(Zeile + 9) - 12;           // -12 = -10 für </Trainer> + -2 fuer /r
         strncpy(tmp2, Zeile + 9, len);
         tmp2[len] = '\0';
         printf("Trainername: %s\n", tmp2);
         Team->Coach = calloc(len + 1, sizeof(char));
         if(Team->Coach)
            strncpy(Team->Coach, Zeile + 9, len);
      }
   } while(strncmp(Zeile, "</Team>", 7) !=  0);
   TeamCounter++;
}

void loadPlayer(char *tmp, FILE *fp, TTeam *Team)
{
   char *Zeile;
   char tmp2[101];
   int len = 0;
   TPlayer *Player = Team->Player + Team->Size;

   do
   {
      Zeile = tmp;
      fgets(tmp, 100, fp);
      while((*Zeile == ' ') || (*Zeile == 9))
         Zeile++;
      if(strncmp(Zeile, "</Player>", 9) != 0)
      {
         /* Ausgabe Spielername */
         if(strncmp(Zeile, "<Name>", 6) == 0)
         {
            len = strlen(Zeile + 6) - 9;           // -9 = -7 für </Name> + -2 fuer /r
            strncpy(tmp2, Zeile + 6, len);
            tmp2[len] = '\0';
            printf("Spielername: %s\n", tmp2);
            Player->Name = calloc(len + 1, sizeof(char));
            if(Player->Name)
               strncpy(Player->Name, Zeile + 6, len);
         }

         /* Ausgabe Geburtstag */
         if(strncmp(Zeile, "<Birthday>", 10) == 0)
         {
            len = strlen(Zeile + 10) - 13;           // -13 = -11 für </Birthday> + -2 fuer /r
            strncpy(tmp2, Zeile + 10, len);
            tmp2[len] = '\0';
            printf("Geburtstag: %s\n", tmp2);

            Player->Birthday = calloc(1, sizeof(TDate));
            if(Player->Birthday)
            {
               Player->Birthday->Day = atoi(Zeile +10);
               Player->Birthday->Month = atoi(Zeile +13);
               Player->Birthday->Year = atoi(Zeile + 16);
            }
         }

         /* Ausgabe Trikotnummer */
         if(strncmp(Zeile, "<TricotNr>", 10) == 0)
         {
            len = strlen(Zeile + 10) - 13;           // -13 = -11 für </TricoNr> + -2 fuer /r
            strncpy(tmp2, Zeile + 10, len);
            tmp2[len] = '\0';
            printf("TricotNr: %s\n", tmp2);

            Player->Number = atoi(Zeile + 10);
         }

         /* Ausgabe Tore */
         if(strncmp(Zeile, "<Goals>", 7) == 0)
         {
            len = strlen(Zeile + 7) - 10;           // -10 = -8 für </Trainer> + -2 fuer /r
            strncpy(tmp2, Zeile + 7, len);
            tmp2[len] = '\0';
            printf("Tore: %s\n", tmp2);

            Player->Goals = atoi(Zeile + 7);
         }
      }
   } while(strncmp(Zeile, "</Player>", 9) != 0);
   (Team->Size)++;
}

int save(TTeam *D)
{
   FILE *wp;
   int i;

   if(askYesOrNo("Moechten Sie Ihre Eingaben speichern (j/n) ? ") == 1)
   {
      wp = fopen(PATH, "w");

      if (wp == NULL)
      {
         printf("Datei um Daten zu speichern konnte nicht geöffnet werden!\n");
         waitForEnter();
      }
      else
      {
         {
            fprintf(wp, "<Daten>\n");

            for(i = 0; i < TeamCounter; i++)
               saveTeam((Teams+i), wp);

            fprintf(wp, "</Daten>");
         }
      fclose(wp);
      }
   }
   return 0;
}

static void saveTeam(TTeam *D, FILE *wp)
{
   int i;
   fprintf(wp," <Team>\n");
   fprintf(wp,"  <Name>%s</Name>\n", D->Name);
   fprintf(wp,"  <Trainer>%s</Trainer>\n", D->Coach);

   for(i = 0; i < D->Size; i++)
   {
      savePlayer(D->Player + i, wp);
   }

   fprintf(wp," </Team>\n");
}

static void savePlayer(TPlayer *P, FILE *wp)
{
   fprintf(wp, "  <Player>\n");
   fprintf(wp, "   <Name>%s</Name>\n", P->Name);
   fprintf(wp, "   <Birthday>%02i.%02i.%4i</Birthday>\n", P->Birthday->Day, P->Birthday->Month, P->Birthday->Year);
   fprintf(wp, "   <TricotNr>%02i</TricotNr>\n", P->Number);
   fprintf(wp, "   <Goals>%i</Goals>\n", P->Goals);
   fprintf(wp, "  </Player>\n");
}
