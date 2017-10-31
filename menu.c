#include <stdio.h>
#include "tools.h"

int getMenu()
{
   int choice = 1;
   do
   {
      clearScreen();

      printf("Mannschaften-Verwaltung V0.2\n");
      printf("============================\n\n");
      printf("1. Neue Mannschaften anlegen\n");
      printf("2. Spieler hinzufuegen\n");
      printf("3. Spieler loeschen\n");
      printf("4. Mannschaft loeschen\n");
      printf("5. Suchen\n");
      printf("6. Sortieren\n");
      printf("7. Auflisten\n");
      printf("8. Programm beenden\n");
      printf("\n");
      scanf("%i", &choice);
      clearBuffer();

   } while(choice > 0 && choice < 9);
   // Zeichenkette mit Menuetitel
   // Array von Zeichenkette mit Menupunkte
   // Array Anzahl der Menupunkte (Texte
   return choice;
}
