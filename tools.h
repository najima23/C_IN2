#ifndef TOOLS_H
   #define TOOLS_H TOOLS.H

   void clearBuffer();
   int  askAgain();
   short askYesOrNo(char *);

#endif




// ***************************************************************************************************
// ***************************************************************************************************
// ************************* PP (Peters Programm) ****************************************************
// ***************************************************************************************************
// ***************************************************************************************************


#ifndef TOOLS_H                                       // Includewächter
   #define TOOLS_H TOOLS_H                            // Dateiname in groß und mit Groundline

   /**************************************************************************************************
   * PROTOTYPES
   **************************************************************************************************/

   void clearScreen();                                // Leert den Bildschirm
   void clearBuffer();                                // Leert den Tastaturpuffer
   void waitForEnter();                               // Eingabeaufforderung zur Betätigung der Entertaste
   short askYesOrNo(char *);                          // Abfrage, ob das Programm wiederholt werden soll

#endif
