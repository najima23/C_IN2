/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           search.c
*** BESCHREIBUNG:    Dieses Modul ist beinhaltet zum Einen die Hash-Funktion (z.B. Divisionsrest)
***                  und zum Anderen die eigentliche Suchfunktion
*** GLOBALE FKT:     calcDivisionsrest
***                  search
*** LOKALE FKT:      -/-
*****************************************************************************************************
****************************************************************************************************/
#include "datastructure.h"
#include "sort.h"


int calcDivRest(TPlayer *P)
{
    int sum = 0;
    char *tmp = P->Name;
    while(*tmp)
    {
        sum += toUpper(*tmp);       // toupper in ctype.h -> klein in Großbuchstaben
        tmp++;
    }
    return(sum % MAXINDEX);
}
