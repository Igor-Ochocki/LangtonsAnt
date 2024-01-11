# LangtonsAnt
## Kompilacja
Program kompilowany jest przy użyciu pliku Makefile poprzez wywołanie w środowisku Unix komendy **_make_**
Do debugowania przygotowany został specjalny skrypt Makefile wywoływany za pomocą komendy **_make debug_** a następnie uruchamiany debuger przy pomocy **_gdb langton.out_**
## Uruchomienie programu
Program uruchamiany jest poprzez wywołanie komendy (po uprzedniej kompilacji) **_.langton.out [parametr] [wartość] [parametr] [wartość] ..._**
### Opis parametrów
#### Wczytywanie planszy
**-r** [nazwa_pliku] - wczytuje planszę z podanego pliku jako początkową
#### Generowanie planszy
**-g** [liczba] - losowe wypełnienie czarnymi polami początkowej planszy w stosunku procentowym na podstawie wartości [liczba]
> Domyślnie g = 0
**-m** [liczba] - wymiar planszy -> liczba wierszy
> Domyślnie m = 5
**-n** [liczba] - wymiar planszy -> liczba kolumn
> Domyślnie n = 5
**-d** [liczba] - kierunek początkowy mrówki przyjmujący wartości 0-3, gdzie:
> 0 - mrówka patrzy w górę
> 1 - mrówka patrzy w prawo
> 2 - mrówka patrzy w dół
> 3 - mrówka patrzy w lewo
> Domyślnie d jest losowe
#### Symulacja mrówki
**-i** [liczba] - ilość iteracji mrówki do wykonania
> Domyślnie i = 10
#### Wypisywanie planszy
**-f** [nazwa_pliku] - zapisuje kolejne iteracje mrówki do pliku w folderze output postaci output/nazwa_pliku_nriteracji
> Domyślne kolejne iteracje wypisywane są na stdout
> Podstawowy folder zapisu to /output/
## Przykładowe wywołania
### Poprawne wywołanie programu
> **_./langton.out -g 20 -m 5 -n 4 -d 2_**
> **_./langton.out -r "test.txt" -i 40_**
> **_./langton.out -f "plansza_po_iteracji_nr"_**
### Niepoprawne wywołanie programu
> **_./langton.out -g -f "robert" -d -i -m -n_**
> **_./langton.out -g "alamakota"_**
> **_./langton.out -r 123 -m -123 -n 0_**
