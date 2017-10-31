#ifndef TOOLS_H
   #define TOOLS_H TOOLS.H

   void clearBuffer();           // Leert den Tastaturpuffer
   void clearScreen();           // Leert den Terminal
   short askYesOrNo(char *);     // Ja/Nein Abfrage
   void waitForEnter();          // Eingabeaufforderung der Entertaste
   void printLine(char, int);    // Gibt ein Zeichen mit der gewuenschten Anzahl aus

#endif
