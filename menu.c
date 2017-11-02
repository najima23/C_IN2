/****************************************************************************************************
*****************************************************************************************************
*** MODUL:          menu.c
*** BESCHREIBUNG:   Zeichnet das Hauptmenü und nimmt die Auswahl der Unterfunktionen entgegen.
*** GLOBALE FKT:    getMenu
*** LOKALE FKT:
*****************************************************************************************************
****************************************************************************************************/

#include <stdio.h>
#include "tools.h"
#include <string.h>
#include "main.h"

int getMenu()
{
   int choice = 0;

   /* Menu Auswahl */
   printf("\nIhre Wahl: ");
   scanf("%i",&choice);
   clearBuffer();
   return choice;
}
