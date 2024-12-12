# Bankowy system zarządzania klientami
## O projekcie
Program został zrealizowany w ramach projektu zaliczeniowego z zajęć Programowanie obiektowe, prowadzący dr inż. Wojciech Frohmberg. Głównym językiem wykorzystanym w tym programie jest język C++, do integracji z bazą danych SQL użyta została biblioteka SQLite3, a interfejs graficzny zaimplementowany został przy użyciu biblioteki wxWidgets. Najważniejszymi założeniami projektu było poznanie i praktyczne wykorzystanie czterech podstawowych filarów programowania obiektowego: abstrakcja, hermetyzacja, polimorfizm i dziedziczenie.
## Autor
Imię i nazwisko: **Mikołaj Długołęcki**<br/>
Nr indeksu: **160244**<br/>
Grupa: **L5**
## Kompilacja i uruchomienie programu
Aby skompilować program:
```
g++ main.cpp .\src\* -o app.exe -I. -L. sqlite3.lib -lsqlite3 -I src
```
Aby uruchomić program:
```
.\app.exe
```