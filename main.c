/****************************************************************************************************
*****************************************************************************************************
*** MODUL:          main.c
*** BESCHREIBUNG:   Hauptprogramm der Mannschaften-Verwaltung
*****************************************************************************************************
****************************************************************************************************/

#include "teams.h"
#include "menu.h"
#include "datastructure.h"

int main()
{
    int input;
    char *menuTitel = "Mannschaften-Verwaltung V0.3";       // Menutitel deklaration
    char *menuItems[] = {"Neue Mannschaften anlegen",       // Untermenu deklaration
                         "Spieler hinzufuegen",
                         "Spieler loeschen",
                         "Mannschaft loeschen",
                         "Suchen",
                         "Sortieren",
                         "Auflisten",
                         "Programm beenden"};
    while( (input = getMenu(menuTitel, menuItems, 8)) != 8)  // Menuauswahl
    {
         switch(input)
         {
            case 1: createTeam();         break;
            case 2: addPlayer();          break;
            case 3: deletePlayer();       break;
            case 4: deleteTeam();         break;
            case 5: searchPlayer();       break;
            case 6: sortTeams();          break;
            case 7: listTeams();          break;
         }
    }

    return 0;
}


