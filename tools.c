#include <stdio.h>


/**********************************************************
 * Funktion:      clearBuffer
 * Beschreibung:  Leert den Tastaturpuffer
**********************************************************/
void clearBuffer()
{
   while (getchar() != '\n')
      ;
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





