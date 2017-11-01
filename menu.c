#include <stdio.h>
#include "tools.h"
#include <string.h>
#include "main.h"

int getMenu()
{
   char *Menu[2][10];
   int numberOfItems = 0,
       j             = 0,
       choice        = 0;

   /* Hauptmenu */
   Menu [0][0] = "Mannschaften-Verwaltung V0.2";
   Menu [0][1] = "1. Neue Mannschaften anlegen";
   Menu [0][2] = "2. Spieler hinzufuegen";
   Menu [0][3] = "3. Spieler loeschen";
   Menu [0][4] = "4. Mannschaft loeschen";
   Menu [0][5] = "5. Suchen";
   Menu [0][6] = "6. Sortieren";
   Menu [0][7] = "7. Auflisten";
   Menu [0][8] = "8. Programm beenden";
   numberOfItems = 9;

   /* Ausgabe Menu */
   printf("%s\n", Menu[0][j]);
   printLine('-',10);
   for(j=1; j<numberOfItems; j++)
   {
      printf("%s\n", Menu[0][j]);
   }

   /* Menu Auswahl */
   printf("\nIhre Wahl: ");
   scanf("%i",&choice);

   return choice;
}
