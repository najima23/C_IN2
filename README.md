# IN2
Übung Informatik 2 - Kempfer

Übung 03:

In dieser Übungsaufgabe des Projektes “Mannschafts-Verwaltung“ sollen zum Einen die Eingabe von neuen Mannschaften und neuen Spielern so- wie zum Anderen die Ausgabe auf dem Bildschirm erstellt werden.

Für die Eingabe einer neuen Mannschaft (Funktion createTeam im Mo- dul teams.c) soll der Benutzer die Namen von Mannschaft und Trainer eingeben; die Anzahl der Spieler wird erst einmal auf 0 gesetzt. In einer Schleife werden dann die Spieler erfasst (Funktion createPlayer im Modul teams.c; diese Funktion wird nur zur Eingabe eines Spielers ver- wendet!). Hierbei werden für einen Spieler jeweils Name, Geburtsdatum (Datumseingabe aus der 1. Übungsaufgabe) und die Trikotnr. erfasst; die Anzahl der bereits geschossenen Tore soll auf 0 gesetzt werden. Nach der erfolgreichen Eingabe eines Spielers (also wenn die Funktion crea- tePlayer abgeschlossen ist) muss die Anzahl der Spieler in der Mann- schaft um eins erhöht und der Benutzer gefragt werden, ob noch ein wei- terer Spieler eingegeben werden soll (Funktion askYesOrNo im Modul tools.c). Die Eingabe von Trainernamen und Spielergeburtstag sind optional; alle anderen Eingaben sind Pflichteingaben.

Entsprechend der Beispielausgaben soll die Ausgabe aller Mannschaften (Funktion listTeams im Modul teams.c) erstellt werden. Für eine best- mögliche Wiederverwendbarkeit sollte diese Funktion noch unterteilt wer- den: Die Funktion listTeams ruft in einer Schleife für alle Mannschaften die Funktion listOneTeam auf, in der alle Daten einer Mannschaft auf dem Bildschirm ausgegeben werden. In dieser Funktion wird in einer Schleife über alle Spieler der Mannschaft die Funktion listOnePlayer aufgerufen. Hier werden in einer Zeile die Daten eines Spielers (Name, Trikotnr. und Geburtsdatum; siehe Beispielausgabe) ausgegeben.

 Im Modul datetime.c werden für die Ein- und Ausgabe des Geburtsda- tums folgende Funktionen hinzugefügt:
- getDate
- printDate

Die Funktion getDate kann teilweise aus der main.c der 1. Übungsauf- gabe übernommen werden. Beachten Sie aber, dass in der Datenstruktur nur ein Zeiger auf die Datumsstruktur gespeichert wird. D.h. es muss in dieser Funktion auch noch Speicher für die Datumsstruktur reserviert werden.

Die Funktion printDate erhält einen Zeiger auf ein Datum vom Typ TDate und gibt dieses im Format dd.mm.yyyy auf dem Bildschirm aus (Tag und Monat zweistellig und das Jahr vierstellig jeweils mit führenden Nullen).

Da in den Datenstrukturen die Zeichenketten immer als Zeiger auf char und nicht Array von char definiert sind, müssen für alle Zeichenketten jeweils Speicherbereiche entsprechend der Eingabelängen reserviert wer- den. Dazu soll im Modul tools.c eine Funktion getText definiert wer- den, die alle hierfür notwendigen Aufgaben für die Eingabe eines Textes durchführt. Diese Funktion erhält eine Eingabeaufforderung als Zeichen- kette, die maximale Eingabelänge für den einzugebenden Text, einen Wahrheitswert, ob auch ein leerer String als Eingabe zulässig ist sowie einen Zeiger auf eine Zeichenkette (also ein Zeiger auf Zeiger auf char); dieser Zeiger auf Zeichenkette soll jeweils auf die Zeichenketten in der Datenstruktur zeigen. In der Funktion soll ein Text mittels scanf in eine lokale, dynamisch reservierte Zeichenkette eingelesen werden (diese muss am Ende der Funktion wieder freigegeben werden!). Dann soll ent- sprechend der Länge des eingegebenen Textes Speicher reserviert wer- den (über den Parameter Zeiger auf Zeichenkette sollen die Zeichenket- ten in den Datenstrukturen auf diesen jeweils reservierten Speicherbe- reich zeigen!). Dann wird der eingegebene Text in den reservierten Spei- cher kopiert. Die Funktion soll eine 1 zurückgeben, wenn alles geklappt hat, sonst eine 0. Damit soll mit dem Aufruf
getText("Name: ", 50, 0, &((Teams + TeamCounter)->Name));
einen Text eingelesen (max. 50 Zeichen; eine leere Eingabe ist nicht zu- lässig) und der Zeiger auf diesen Text in der Datenstruktur gespeichert werden können. Das Ermitteln der Textlänge sowie das Kopieren der Texte können mittels der Funktionen strlen und strcpy aus der string.h erfolgen.

Analog zur Funktion getText soll im Modul tools.c auch noch eine Funktion getNumber für die Eingabe von Zahlen definiert werden. Hier- bei braucht aber kein Speicher reserviert werden. Mit zwei zusätzlichen Parametern Von und Bis kann ein Zahlenbereich angegeben werden, der von der Funktion auch gleich geprüft wird. Diese Funktion könnte z.B. wie folgt aufgerufen werden:
getNumber("Trikot-Nr.: ", &((Teams + TeamCounter)->TricotNr), 1, 99);
Die Funktion würde dabei erst dann verlassen werden, wenn der Benut- zer eine gültige Zahl zwischen 1 und 99 eingegeben hat.

Generell soll immer mit Zeigern anstelle von Arrays gearbeitet werden!
Vergessen Sie nicht, dass bei Programmende alle reservierten Speicher- bereiche wieder freigegeben werden müssen!

####################

Übung 02:

In der zweiten Übungsaufgabe soll das Projekt mit den Quellcode- und Headerdateien sowie die Datenstruktur erstellt werden. Auch sollen eini- ge einfache Funktionen bereits erstellt werden.
Das Projekt soll jetzt aus folgenden Dateien bestehen – einige davon ha- ben wir bereits in der ersten Übungsaufgabe erstellt:
datastructure.h
main.c
teams.c + teams.h
datetime.c + datetime.h
menu.c + menu.h
tools.c + tools.h
(Definition der Datenstrukturen) (Hauptprogramm)
(Verwaltung der Mannschaften) (Datums- und Uhrzeitfunktionen) (Funktionalität für die Menüs) (Hilfsfunktionen)
In der Headerdatei datastructure.h sollen die Datenstrukturen der Datenbank mit typedef definiert werden. Die Datenstrukturen sollen wie folgt aussehen (bitte alle Bezeichnungen auf Englisch).
- Datentyp TDate: Tag, Monat und Jahr als ganze Zahlen (sollte von der ersten Aufgabe bereits vorhanden sein)
- Datentyp TPlayer: Spielernamen als Zeiger auf Zeichen (kein char- Array!), Geburtsdatum vom Typ Zeiger auf TDate sowie die Trikotnr. und die Anzahl der geschossenen Tore als ganze Zahlen.
- Datentyp TTeam: Namen der Mannschaft und des Trainers als Zeiger auf Zeichen (auch hier keine char-Arrays!), die Anzahl der Spieler in der Mannschaft als ganze Zahl sowie die Spieler als Array vom Typ TPlayer. Das Array soll MAXPLAYER Elemente aufnehmen können; MAXPLAYER ist eine Konstante mit dem Wert 23 und wird auch in der datastructure.h definiert.
Neben den Datenstrukturen soll hier mit der Speicherklasse extern auf die Variablen TeamCounter (ganze Zahl) und Teams (Array vom Daten- typ TTeam) verwiesen werden; beide Variablen sollen im Modul teams.c als globale Variablen definiert werden.
Im Modul team.c werden folgende Funktionen definiert, die vom Haupt- programm entsprechend der Menüauswahl aufgerufen werden sollen. Im
ersten Schritt haben alle Funktionen keine Parameter und geben nichts zurück. Jede Funktion soll nur ihren Funktionsnamen auf dem Bildschirm ausgeben und anschließend auf das Drücken der Eingabetaste warten (siehe Funktion waitForEnter im Modul tools.c). Die eigentlichen Funktionalitäten kommen erst in den nächsten Übungsaufgaben.
- createTeam
- deleteTeam
- addPlayer
- deletePlayer - searchPlayer - sortTeams
- listTeams
Ferner sollen hier die globalen Variablen (siehe oben) TeamCounter und ein Array namens Teams vom Typ TTeam mit MAXTEAMS Elementen definiert werden; MAXTEAMS ist eine Konstante mit dem Wert 10 und wird in der Headerdatei datastructure.h definiert.
Im Modul menu.c wird folgende Funktion definiert:
- getMenu
Diese Funktion erhält eine Zeichenkette mit dem Menütitel und ein Array von Zeichenketten, in denen die Menüpunkte stehen (so wie sie auf dem Bildschirm erscheinen sollen) sowie die Anzahl der Menüpunkte. D.h. die Texte des Titels und der Menüpunkte werden vom Aufrufer vorgegeben; dadurch können wir diese Funktion später auch für Untermenüs verwen- den. Die Funktion soll den gewählten Menüpunkt als Zahl zurückgeben. In der Funktion wird in einer Schleife erst der Bildschirm gelöscht (siehe Funktion clearScreen im Modul tools.c), dann der Menütitel sowie die einzelnen Menüpunkte ausgegeben. Nach den Menüpunkten soll mit einer Leerzeile Abstand eine Eingabeaufforderung auf dem Bildschirm erscheinen. Dann darf der Benutzer die Nummer des gewünschten Menüpunktes eingeben. Die Schleife darf nur verlassen werden, wenn der Benutzer eine gültige Eingabe (zwischen 1 und der Anzahl der Menü- punkte) eingegeben hat.
Das Modul tools.c aus der ersten Übungsaufgabe soll um eine Funkti- on erweitert werden:
- printLine
Diese Funktion erhält ein Zeichen und eine Anzahl als Parameter und gibt nichts zurück. In der Funktion soll das angegebene Zeichen entspre- chend der Anzahl mehrmals hintereinander ausgegeben werden. Z.B. wird mit dem Aufruf printLine('-', 50); eine Linie von 50 Minus- zeichen ausgegeben. Diese Funktion kann bei der Ausgabe der Menüs sowie der Auflistung der Datensätze gut verwendet werden.

 In der Datei main.c wird nur die main-Funktion definiert. Mittels Include- Anweisungen werden die notwendigen Headerdateien mit den Funktions- prototypen der einzelnen Module eingefügt. In der main-Funktion werden erst die Texte für das Menü definiert, dann wird in einer Schleife das Hauptmenü (Funktion getMenu im Modul menu.c) aufgerufen und dem Ergebnis entsprechend die dazugehörige Funktion aus dem Modul teams.c aufgerufen. Die Schleife darf erst dann verlassen werden, wenn der Benutzer den Menüpunkt Programmende gewählt hat.
Kommentieren Sie das Programm. Dazu gehört auch ein Modulheader und zu jeder Funktion ein Funktionsheader (siehe Skript “Grundlagen der Informatik“ Kapitel 5.3 und 5.4)! Achten Sie auch auf Ihre Programm- struktur (Einrückungen, Leerzeichen und -zeilen).

####################

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
