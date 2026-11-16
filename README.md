# Code_128_Barcode_Encoder

## Build- und Startanleitung

### Kurzbeschreibung
Dieses Programm wandelt eine ASCII-Eingabe in die entsprechende Code-128-Symbolsequenz des Subset B um.

### Vorraussetzung
- CMake 4.4 oder neuer
- CLion Toolchain MinGW und Generator Ninja 
- C++26 oder neuer
- Git und Internet für Download von Catch2

### Bauen und starten
1. Den Projektordner mit CMakeLists.txt in CLion öffnen.
2. Toolchain MinGW und Generator Ninja auswählen
2. Beim ersten Build CMake Catch2 herunterladen lassen.
3. Oben rechts als Target "Code_128_Barcode_Encoder" auswählen und Run klicken. 
4. In Run-Konsole Text eingeben und Enter drücken. 
5. Programm gibt Symbolwerte aus und fragt nach nächster Eingabe. 
6. Enter bei leerer Eingabe beendet das Programm.

----
Beispiel:

Text eingeben (Leeres Enter beendet): HELLO123

104 40 37 44 44 47 17 18 19 8 106

------

## Kurze Designbeschreibung
- main.cpp übernimmt Ein- und Ausgabe
  - liest eine ganze Zeile
  - ruft den Encoder auf 
    - zeigt die Symbolfolge 
    - oder eine Fehlermeldung mit der Fehlerposition
- Encoder.cpp enthält den Business code 
  - prüft die Zeichen
  - wandelt sie in Subset-B-Symbolwerte um 
  - berechnet Checksumme 
- EncoderTests.ccp für Tests
