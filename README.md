# virtual-processor

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
