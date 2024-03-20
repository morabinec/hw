# Program pro zobrazení šachovnice

## Popis úkolu
Úkolem je realizovat program, který zobrazí na obrazovce šachovnici.

Vstupem programu jsou dvě celá čísla - velikost šachovnice (počet políček na šířku a výšku) a velikost políčka (počet znaků na výšku a šířku jednoho políčka).

Výstupem programu je zobrazená šachovnice. Šachovnice bude tvořena znaky mezera (bílá pole) a znakem X (černá pole). Celá šachovnice bude orámovaná. V levém horním rohu bude umístěno vždy pole bílé. Šachovnice je čtvercová (počet políček je stejný v obou směrech), políčka jsou rovněž čtvercová (počet znaků na políčko je shodný v obou směrech).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:
- na vstupu nejsou dvě platná celá čísla,
- čísla na vstupu jsou záporná nebo nulová.

## Ukázka práce programu
```c
Zadejte pocet poli:
5
Zadejte velikost pole:
3
+---------------+
|   XXX   XXX   |
|   XXX   XXX   |
|   XXX   XXX   |
|XXX   XXX   XXX|
|XXX   XXX   XXX|
|XXX   XXX   XXX|
|   XXX   XXX   |
|   XXX   XXX   |
|   XXX   XXX   |
|XXX   XXX   XXX|
|XXX   XXX   XXX|
|XXX   XXX   XXX|
|   XXX   XXX   |
|   XXX   XXX   |
|   XXX   XXX   |
+---------------+
Zadejte pocet poli:
8
Zadejte velikost pole:
4
+--------------------------------+
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
+--------------------------------+
Zadejte pocet poli:
2
Zadejte velikost pole:
0
Nespravny vstup.
Zadejte pocet poli:
asdf
Nespravny vstup.
```
