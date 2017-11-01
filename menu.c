#include <stdio.h>
#include "tools.h"
#include <string.h>
#include <main.h>

int getMenu()
{
   int choice = 1;
   do
   {
      clearScreen();

      strcpy(Menu);
      printf("\n");
      scanf("%i", &choice);
      clearBuffer();

   } while(choice > 0 && choice < 9);
   // Zeichenkette mit Menuetitel
   // Array von Zeichenkette mit Menupunkte
   // Array Anzahl der Menupunkte (Texte
   return choice;
}
