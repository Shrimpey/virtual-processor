# virtual-processor

Uzywanie skryptu make-test.sh na linuxie:
1. Wrzucamy plik z rozszerzeniem *.s do folderu /tests (ma on zawierac instrukcje dla assemblera, przyklad w pliku fmul_1.s)
2. W terminalu wpisujemy "./make-test.sh -f nazwa_pliku" i powinnien sie utworzyc plik .bin wraz ze wszystkimi posrednimi plikami
3. Plik .bin mozemy wrzucic jako file_code.bin do programu i przetestowac dzialanie
4. Plik bin mozemy gdzies potem przeniesc, a reszte plikow mozna skasowac poleceniem "./make-test.sh -r nazwa_pliku" (bez specyfikowania rozszerzenia)

P.S. do tego potrzebne sa komendy avr, nie pamietam czy one sa z arduino czy jakos standardowo, w kazdym razie ja instalowalem "apt-get install arduino"
