#!/bin/bash

for file in *.s; do
    [ -e "$file" ] || continue
    echo "Processing  $file..."
    "$PWD"/make-test.sh -f "${file%$".s"}"
    cd ..
    "$PWD"/syko.exe 30 30 zeroPC
    cd tests
    cp "$PWD"/../file_data.bin "$PWD"/"binary data"/${file%$".s"}_out.bin
    echo ""
done

cd "$PWD"/binary\ data/

echo "Comparing files..."
"$PWD"/compare.sh
