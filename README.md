# virtual-processor

##Tworzenie testow:
1. Tworzymy plik z instrukcjami asemblera z rozszerzeniem .s i wstawiamy do folderu "/tests"
2. Postepujemy zgodnie z poleceniami do make-test.sh (instrukcje znajduja sie nizej)
3. Postepujemy zgodnie z poleceniami do compare.sh (instrukcje znajduja sie nizej)
4. Otrzymane pliki .dec i .hex beda wstawiane do sprawozdania jako wyniki testow

###Uzywanie skryptu make-test.sh:
1. Wrzucamy plik z rozszerzeniem *.s do folderu "/tests" (ma on zawierac instrukcje dla assemblera, przyklad w pliku fmul_1.s)
2. W terminalu wpisujemy "./make-test.sh -f nazwa_pliku" (bez specyfikowania rozszerzenia) i powinnien sie utworzyc plik .bin wraz ze wszystkimi posrednimi plikami
3. Plik .bin mozemy wrzucic jako file_code.bin do programu i przetestowac dzialanie
4. Plik bin mozemy gdzies potem przeniesc (najlepiej do folderu "/tests/binary codes"), a reszte plikow mozna skasowac poleceniem "./make-test.sh -r nazwa_pliku" (bez specyfikowania rozszerzenia)

_P.S. do tego potrzebne sa komendy avr, nie pamietam czy one sa z arduino czy jakos standardowo, w kazdym razie ja instalowalem "apt-get install arduino"_


###Uzywanie skryptu compare.sh:
1. Tworzymy plik z danymi wejsciowymi do testu i kopiujemy go do "tests/binary data" zmieniajac nazwe na "nazwa_in.bin"
2. Uruchamiamy procesor dla utworzonych wczesniej opcodow i dostajemy dane wyjsciowe
3. Dane wyjsciowe kopiujemy do "tests/binary data" zmieniajac nazwe na "nazwa_out.bin"
4. Uruchamiamy "./compare.sh" i zostaja utworzone po dwa pliki do kazdego testu - .dec i .hex, stanowia one porownanie danych w dec i hex
