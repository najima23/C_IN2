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
#define PATH  "IN2/Test.xml"

#include <stdio.h>
#include <string.h>
#include "database.h"
#include "datastructure.h"
#include "tools.h"

void loadTeam(char *, FILE *);
void loadPlayer(char *tmp, FILE *fp);
void saveTeam(TTeam *, FILE *);

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
         }
      } while(strncmp(Zeile, "</Daten>", 8) != 0);
      fclose(fp);
   }
   waitForEnter();
   return 0;
}

int save()
{
   FILE *wp;

   while(askYesOrNo("Moechten Sie Ihre Eingaben speichern (j/n) ? ") != 0)
   {
      wp = fopen(PATH, "w+");

      if (wp == NULL)
      {
         printf("Datei um Daten zu speichern konnte nicht geöffnet werden!\n");
         waitForEnter();
      }
      else
      {
         fprintf(wp, "<Daten>\n");
//         saveTeam(wp);            <-- da fehlt noch eine Parameter
      }
   }
   return 1;
}

void loadTeam(char *tmp, FILE *fp)
{
   char *Zeile;
   char tmp2[101];
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
         len = strlen(Zeile + 6) - 9;           // -9 = -7 für </Name> + -2 fuer /r
         strncpy(tmp2, Zeile + 6, len);
         tmp2[len + 1] = '\0';
         printf("Manschaftsname: %s\n", tmp2);
      }

      /* Ausgabe Trainername */
      if(strncmp(Zeile, "<Trainer>", 9) == 0)
      {
         len = strlen(Zeile + 9) - 12;           // -12 = -10 für </Trainer> + -2 fuer /r
         strncpy(tmp2, Zeile + 9, len);
         tmp2[len + 1] = '\0';
         printf("Trainername: %s\n", tmp2);
      }
   } while(strncmp(Zeile, "</Team>", 7) !=  0);
}

void loadPlayer(char *tmp, FILE *fp)
{
   char *Zeile;
   char tmp2[101];
   int len = 0;
   do
   {

      Zeile = tmp +1;
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
            tmp2[len + 1] = '\0';
            printf("Spielername: %s\n", tmp2);
         }

         /* Ausgabe Geburtstag */
         if(strncmp(Zeile, "<Birthday>", 10) == 0)
         {
            len = strlen(Zeile + 10) - 13;           // -13 = -11 für </Birthday> + -2 fuer /r
            strncpy(tmp2, Zeile + 10, len);
            tmp2[len + 1] = '\0';
            printf("Geburtstag: %s\n", tmp2);
         }

         /* Ausgabe Trikotnummer */
         if(strncmp(Zeile, "<TricotNr>", 10) == 0)
         {
            len = strlen(Zeile + 10) - 13;           // -13 = -11 für </TricoNr> + -2 fuer /r
            strncpy(tmp2, Zeile + 10, len);
            tmp2[len + 1] = '\0';
            printf("Trainername: %s\n", tmp2);
         }

         /* Ausgabe Tore */
         if(strncmp(Zeile, "<Goals>", 7) == 0)
         {
            len = strlen(Zeile + 7) - 10;           // -10 = -8 für </Trainer> + -2 fuer /r
            strncpy(tmp2, Zeile + 9, len);
            tmp2[len + 1] = '\0';
            printf("Trainername: %s\n", tmp2);
         }
      }
   } while(strncmp(Zeile, "</Player>", 9) != 0);
}

void saveTeam(TTeam *Player, FILE *wp)
{
/*   int i;

   for (i = 0; i < (i + Player->Size); i++);
   {
      fprintf(wp,"   <Team>\n");
      fprintf(wp,"      <Name>%s</Name>\n", Player->Name);
      fprintf(wp,"      <Trainer>%s</Trainer", Player->Coach);
   }
   fclose(wp);
   waitForEnter(); */  // Funktioniert aktuell nicht
}

void savePlayer()
{

}
