#include <stdio.h>
#include <stdlib.h>
#include "escapesequenzen.h"
#include "tools.h"


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
//   system("CLS");    // für Windows
   system("clear");  // für Linux
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

      switch (input)                                           // Überprüfung des Chars
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
 * Beschreibung:  Eingabeaufforderung zur Betätigung
 *                der Eingabetaste (Piratentaste, arrrrr)
 * Parameter:     -/-
 * Ergebnis:      -/-
**********************************************************/
void waitForEnter()
{
   char c;

   printf("Bitte <ENTER> betaetigen");
   if ( (c = getchar()) != '\n')
      clearBuffer();
}

/**********************************************************
 * Funktion:     printLine
 * Beschreibung: Gibt ein Zeichen in der gewuenschten
 *               Anzahl aus
 * Parameter:    - 1 Zeichen
 *               - Anzahl der Wiederholungen
 * Ergebnis:     -/-

**********************************************************/
void printLine(char Zeichen, int Anzahl)
{
   int i;
   for (i=0; i<Anzahl; i++)
   {
      printf("%c", Zeichen);
   }
   printf("\n");
}
