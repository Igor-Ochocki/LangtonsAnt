# LangtonsAnt
## Kompilacja
Program kompilowany jest przy użyciu pliku Makefile poprzez wywołanie w środowisku Unix komendy 
```make```
Do debugowania przygotowany został specjalny skrypt wywoływany za pomocą komendy 
```make debug```
a następnie uruchamiany debuger przy pomocy 
```gdb langton.out```
## Uruchomienie programu
Program uruchamiany jest poprzez wywołanie komendy (po uprzedniej kompilacji) 
```
.langton.out [parametr] [wartość] [parametr] [wartość] ...
```
### Opis parametrów
#### Wczytywanie planszy
**-r** [nazwa_pliku] - wczytuje planszę z podanego pliku jako początkową
#### Generowanie planszy
1. **-g** [liczba] - losowe wypełnienie czarnymi polami początkowej planszy w stosunku procentowym na podstawie wartości [liczba]
   - Domyślnie g = 0
1. **-m** [liczba] - wymiar planszy -> liczba wierszy
   - Domyślnie m = 5
1. **-n** [liczba] - wymiar planszy -> liczba kolumn
   - Domyślnie n = 5
1. **-d** [liczba] - kierunek początkowy mrówki przyjmujący wartości 0-3, gdzie:
   - 0 - mrówka patrzy w górę
   - 1 - mrówka patrzy w prawo
   - 2 - mrówka patrzy w dół
   - 3 - mrówka patrzy w lewo
   - Domyślnie d jest losowe
#### Symulacja mrówki
**-i** [liczba] - ilość iteracji mrówki do wykonania
- Domyślnie i = 10
#### Wypisywanie planszy
**-f** [nazwa_pliku] - zapisuje kolejne iteracje mrówki do pliku w folderze output postaci **_output/nazwa_pliku_nriteracji_**
- Domyślne kolejne iteracje wypisywane są na **_stdout_**
- Podstawowy folder zapisu to **_\/output\/_**
## Przykładowe wywołania
### Poprawne wywołanie programu
```
./langton.out -g 20 -m 5 -n 4 -d 2
./langton.out -r "test.txt" -i 40
./langton.out -f "plansza_po_iteracji_nr"
```
### Niepoprawne wywołanie programu
```
./langton.out -g -f "robert" -d -i -m -n
./langton.out -g "alamakota"
./langton.out -r 123 -m -123 -n 0
```
