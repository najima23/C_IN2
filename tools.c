#include <stdio.h>
#include <stdlib.h>
#include "escapesequenzen.h"

int  askAgain();
void clearBuffer();
void clearScreen();
short askYesOrNo(char *);
void waitForEnter();

/**********************************************************
* Funktion:     askAgain
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
* Funktion:     clearBuffer
* Beschreibung: Tastaturpuffer leeren
* Parameter:    -/-
* Ergebnis:     -/-
**********************************************************/
void clearBuffer()
{
   while (getchar() != '\n')
      ;
}

/**********************************************************
* Funktion:     clearScreen
* Beschreibung: Leert die Konsole
* Parameter:    -/-
* Ergebnis:     -/-
**********************************************************/
void clearScreen()
{
   system("CLS");    // f�r Windows
//   system("CLEAR");  // f�r Linux
}

/**********************************************************
 * Funktion:      askYesOrNo
 * Beschreibung:  Nachfrage, ob etwas wiederholt werden soll
 * Parameter:     Promttext in Stringform
 * Ergebnis:      1 wenn j oder J eingegeben wurde,
 *                0 wenn n oder N
**********************************************************/
short askYesOrNo(char *string)
{
   char input;

   do
   {
      printf("%s", string);                                    // Abfrage zum Wiederholen anzeigen

      if ( (input = getchar()) != '\n')                        // Einlesen eines Chars
         clearBuffer();

      switch (input)                                           // �berpr�fung des Chars
      {
         case 'j':
         case 'J': return 1;
         case 'n':
         case 'N': return 0;
         default: input = '\0';
      }
   } while (!input);                                           // Solange nicht ja oder nein eingegeben wurde

   return 0;   // Dummy, sonst gibts Compilerfehler
}

/**********************************************************
 * Funktion:      waitForEnter
 * Beschreibung:  Eingabeaufforderung zur Bet�tigung
 *                der Eingabetaste (Piratentaste, arrrrr)
**********************************************************/
void waitForEnter()
{
   char c;

   printf("Bitte <ENTER> betaetigen");
   if ( (c = getchar()) != '\n')
      clearBuffer();
}
