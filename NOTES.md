# TODO

- [x] Encoder schreiben
- [X] CLI fähig machen
- [X] Unit Test (ein TRUE && FALSE)
- [X] README anlegen
- [X] Designbeschreibung

# Aufgabe

Implementiere ein kleines C++ Programm, das einen gegebenen ASCII-Text in die entsprechende
Code-128-Symbolsequenz des Subset B umwandelt. Der Fokus liegt nicht auf einer vollständigen
Barcode-Rendering-Logik, sondern auf korrekter Codierung und sauberer Implementierung.

## Anforderungen
- [x]  Programmiersprache: C++17 oder neuer
- [X]  Eingabe: ASCII-String, zum Beispiel HELLO123
- [X]  Ausgabe: Liste der Code-128-Symbolwerte inklusive Startcode, Checksumme und Stopcode
- [X]  Implementierung der Code-128-Checksummenberechnung
- [X]  Klare Strukturierung des Codes, zum Beispiel mit Klassen oder Modulen
- [X]  Fehlerbehandlung für ungültige Eingaben

https://de.wikipedia.org/wiki/Code128

---------
Beispiel
Eingabe: HELLO123
Ausgabe: 104 40 37 44 44 47 17 18 19 8 106
---------

# Aufbau vom Code 128

https://www.keyence.eu/dede/ss/products/auto_id/codereader/basic/code128.jsp

https://de.wikipedia.org/wiki/American_Standard_Code_for_Information_Interchange

## Startcode
bestimmt die Zeichenstruktur der nachfolgenden Zeichen.
drei verschiedenen Start-Zeichen (A 103 , B 104, C 105 )

beim B geht ASCII  von 0 bis inkl 95...
95 ist del also nciht in normaller console eingebbar aber ein ASCII zeichen

## Checksumme

(Startwert + Symbolwert * Position im Text + Symbolwert * Position im Text ... modolo 103 = der Rest ist die checksumme 
                                            
## Stopcode

immer 106

# SONSTIGES
char als int ist ASCI also denn wert einfach -32 dann bekommt man die B startzeichen value
ASCI  =    Start-Zeichen B 
32    =    0

## UNIT Test
CMake https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#cmake-targets

https://github.com/catchorg/Catch2/blob/devel/docs/assertions.md?utm_source=chatgpt.com