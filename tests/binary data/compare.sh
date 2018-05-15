#!/bin/bash

for file in *in.bin; do
    	[ -e "$file" ] || continue
	echo "Processing ${file%$"_in.bin"}"
	cmp -l ${file%$"in.bin"}in.bin ${file%$"in.bin"}out.bin | gawk '{printf "%08X %02X %02X\n", $1-1, strtonum(0$2), strtonum(0$3)}' > ${file%$"in.bin"}diff.hex
	cmp -l ${file%$"in.bin"}in.bin ${file%$"in.bin"}out.bin -l > ${file%$"in.bin"}diff.dec

done
