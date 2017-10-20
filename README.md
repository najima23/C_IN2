# IN2
Übung Informatik 2 - Kempfer


Übung 01:

Erstellen Sie als erstes die Headerdatei datastructure.h. In dieser Datei sollen zwei Datenstrukturen mittels typedef deklariert werden:
- TDate: beinhaltet drei Zahlen für Tag, Monat und Jahr
- TTime: beinhaltet drei Zahlen für Stunde, Minute und Sekunde.
Schreiben Sie dann die fehlenden Funktionen zum vorgegebenen Haupt- programm. Diese Funktionen sollen in einem eigenen Modul (z.B. date- time.c) untergebracht werden, da diese in den weiteren Übungs- aufgaben wieder benötigt werden.
Die Funktion isLeapYear (soll von der nächsten Funktion aufgerufen werden) soll als Funktionsergebnis eine ganze Zahl zurückgeben. Diese

Zahl soll als Wahrheitswert angeben, ob das angegebene Jahr (Parame- ter) ein Schaltjahr ist.
Die Funktion isDateValid (soll von der nächsten Funktion aufgerufen werden) soll als Funktionsergebnis eine ganze Zahl zurückgeben. Diese Zahl soll als Wahrheitswert angeben, ob das angegebene Datum (Para- meter Struktur TDate mit Tag, Monat und Jahr) ein gültiges Datum ist. Dabei sollen auch die Schaltjahre berücksichtigt werden.
Die Funktion getDateFromString (wird vom Hauptprogramm aufgeru- fen) soll als Funktionsergebnis eine ganze Zahl zurückgeben. Diese Zahl soll als Wahrheitswert angeben, ob in der angegebenen Zeichenkette (1. Parameter) ein Datum enthalten ist. Dieses Datum soll in Tag, Monat und Jahr (als Zahlen) zerlegt – sozusagen geparst – werden; dabei sind die Zahlen durch Punkte voneinander getrennt; die Punkte müssen nicht unbedingt an den Positionen 3 und 6 stehen (siehe Beispielausgabe)! Natürlich sollen diese drei Zahlen als Datum geprüft werden, ob sie ein gültiges Datum ergeben. Wenn ja, sollen diese drei Zahlen in die überge- bene Datumsstruktur (2. Parameter: Zeiger auf TDate) gespeichert wer- den.
Analog dazu soll auch eine Eingabe einer Uhrzeit möglich sein. Dazu werden folgende Funktionen benötigt:
- isTimeValid: prüft, ob die in der Zeitstruktur (Datentyp TTime) ange- gebene Uhrzeit gültig ist;
- getTimeFromString: liest aus einer Zeichenkette die Stunden, Minu- ten und Sekunden und speichert diese – sofern sie eine gültige Uhrzeit
bilden – in der Zeitstruktur.
Es ist komplett analog zu der Datumseingabe vorzugehen – mit Ausnah- me, dass hier keine Schaltstunden oder Ähnliches existieren und dass die Gültigkeitsprüfung einfacher ist, da hier jede Stunde die gleiche An- zahl von Minuten hat. Außerdem werden zur Trennung der Zahlen Dop- pelpunkte anstelle von Punkten verwendet.
Ferner soll wieder wie im vorigen Semester ein Modul namens tools.c erstellt werden mit Hilfsfunktionen wie
- clearBuffer()
- waitForEnter()
- clearScreen() (hier wird die Funktion system aus der Headerdatei stdlib.h verwendet, z.B. system(“CLS“);)
- askYesOrNo()
Dieses Modul wird im Laufe dieses Semesters immer wieder benötigt und wird noch erweitert werden.
Unter Linux kann auch wieder die Headerdatei escapesequenzen.h verwendet werden (dies funktioniert leider nicht unter Windows).
Die Headerdatei string.h darf für diese Übung nicht verwendet werden!
Kommentieren Sie das Programm. Dazu gehört auch ein Modulheader und zu jeder Funktion ein Funktionsheader (siehe Skript “Grundlagen der Informatik“ Kapitel 5.3 und 5.4)! Achten Sie auch auf Ihre Programm- struktur (Einrückungen, Leerzeichen und -zeilen).

Bei der Abgabe soll die Funktion getDateFromString von Ihnen schrittweise vorgeführt und dabei alle Variableninhalte angezeigt werden.

copyright & all rigths by Dipl.Phys. Gerald Kempfer
