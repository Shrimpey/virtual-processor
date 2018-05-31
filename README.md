# Checklist

## Sprawdzanie testów

### LDI
### MOV
### FMUL
### FMULS
### FMULSU
### ELPM
### EIJMP
### EICALL
### IJMP
+ Brak zastrzeżeń do aktualnych testów, ewentualnie można dodać test, gdzie Zl jest różne od ZH i oba są niezerowe **~Ł**
// Dodane **~P**
### RJMP
+ Brak zastrzeżeń **~Ł**
### STD/LDD
+ Testy są nieaktualne w stosunku do aktualnego działania programy, przesymulować jeszcze raz i zrobić update **~Ł**
// Poprawione **~P**


## Tworzenie testow:
1. Tworzymy plik z instrukcjami asemblera z rozszerzeniem .s i wstawiamy do folderu "/tests"
2. Postepujemy zgodnie z poleceniami do make-test.sh (instrukcje znajduja sie nizej)
3. Postepujemy zgodnie z poleceniami do compare.sh (instrukcje znajduja sie nizej)
4. Otrzymane pliki .hex beda wstawiane do sprawozdania jako wyniki testow

### Uzywanie skryptu make-test.sh:
1. Wrzucamy plik z rozszerzeniem .s do folderu "/tests" (ma on zawierac instrukcje dla assemblera, przyklad w pliku fmul_1.s)
2. W terminalu wpisujemy "./make-test.sh -f nazwa_pliku" (bez specyfikowania rozszerzenia) i skrypt zrobi za nas wszystko co trzeba (skopiuje otrzymany plik z intrukcjami do procesora wraz z czystym plikiem z danymi)
3. Odpalamy procesor ./syko.exe z argumentami, jakich potrzebujemy
4. Dane wyjsciowe (file_data.bin) kopiujemy do "tests/binary data" zmieniajac nazwe na "nazwa_out.bin", gdzie nazwa to nazwa testu

_P.S. do tego potrzebne sa komendy avr, nie pamietam czy one sa z arduino czy jakos standardowo, w kazdym razie ja instalowalem "apt-get install arduino"_


### Uzywanie skryptu compare.sh:
1. Uruchamiamy "./compare.sh" w folderze "binary data" i zostaja utworzone po dwa pliki do kazdego testu - .dec i .hex, stanowia one porownanie danych w dec i hex

## Uzywanie skryptu test-all.sh
Skrypt który dla każdego pliku testowego (z rozszerzeniem .s) w folderze /tests/ powoduje:
1. Uruchomienie skryptu make-test.sh, a co za tym idzie utworzenie odpowiednich plików binarnych
2. Wywołanie programu syko.exe z argumentami 30 30 zeroPC
3. Skopiowanie danych wyjściowych (file_data.bin) do folderu /tests/binary data z odpowiednią nazwą
Następnie uruchamiany jest skrypt compare.sh

Żeby go uruchomic należy wpisać w terminalu ". ./test-all.sh", koniecznie z kropką na początku z poziomu folderu /tests/
