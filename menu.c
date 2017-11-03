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
   int input,
       i;

    do
    {
        clearScreen();

        printf("%s\n", titel);
        printLine('=', strlen(titel));
        printf("\n\n");

        for (i = 0 ; i < numberOfItems ; i++)
            printf("%02d. %s\n", i+1, *(menuItem+i) );

        printf("\nIhre Wahl: ");
        scanf("%d", &input);
        clearBuffer();

    } while (input < 1 || input > numberOfItems);

   return input;
}
