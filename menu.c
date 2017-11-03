/****************************************************************************************************
*****************************************************************************************************
*** MODUL:          menu.c
*** BESCHREIBUNG:   Zeichnet das Hauptmenü und nimmt die Auswahl der Unterfunktionen entgegen.
*** GLOBALE FKT:    getMenu
*** LOKALE FKT:
*****************************************************************************************************
****************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "tools.h"

int getMenu(char *titel, char **menuItem, int numberOfItems)
{
   int input = 0,
       i;

   do
   {
      clearScreen();

      /* Ausgabe Menutitel */
      printf("%s\n", titel);
      printLine('=', strlen(titel));
      printf("\n\n");

      /* Ausgabe Untermenu */
      for (i = 0 ; i < numberOfItems ; i++)
         printf("%02d. %s\n", i+1, *(menuItem+i) );

      /* Usereingabe */
      printf("\nIhre Wahl: ");
      scanf("%d", &input);
      clearBuffer();
   } while (input < 1 || input > numberOfItems);

   return input;
}
