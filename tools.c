#include <stdio.h>
#include "escapesequenzen.h"

void clearBuffer();
int  askAgain();


/**********************************************************
* Funktion: aksAgain
* Beschreibung: Wiederholung: Ja / Nein - Abfrage
* Parameter:    -/-
* Ergebnis:     int - Ergebnis der Abfrage
**********************************************************/
int askAgain(int Pos)
{
   char x;
   do
	{
      POSITION(Pos,1);
      CLEAR_LINE;
      POSITION(Pos,1);
      printf("Moechten Sie noch einmal (j/n)? ");
		scanf("%c", &x);
		if( x != '\n' ) 
      {
         clearBuffer();
      }
      // Fehlermeldung bei Falscheingabe
      if ( x != 'j' && x != 'J' && x != 'n' && x != 'N' )
      {
         printf("\n Falsche Eingabe! Bitte 'j' oder 'n' eingeben!\n");
      }
   } while ( x != 'j' && x != 'J' && x != 'n' && x != 'N' );
   return (x == 'j' || x == 'J');
}

/**********************************************************
* Funktion: clearBuffer
* Beschreibung: Tastaturpuffer leeren
* Parameter:    -/-
* Ergebnis:     -/-
**********************************************************/
void clearBuffer()
{
   while (getchar() != '\n')
      ;
}
