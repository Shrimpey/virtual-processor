#!/bin/bash

POSITIONAL=()
while [[ $# -gt 0 ]]
do
key="$1"

case $key in
    -f|--file)
    EXTENSION="$2"
    shift # past argument
    shift # past value
    ;;
    *)    # unknown option
    POSITIONAL+=("$1") # save it in an array for later
    shift # past argument
    ;;
esac
done
set -- "${POSITIONAL[@]}" # restore positional parameters

if [ ! -z "$EXTENSION" ]; then

echo "Test Generator> Chosen file: ${EXTENSION}"
echo "Test Generator> Generating ${EXTENSION}.o, ${EXTENSION}.elf, ${EXTENSION}.bin and ${EXTENSION}.lst ..."

avr-as -mmcu=atmega2561 ${EXTENSION}.s -o ${EXTENSION}.o
avr-gcc -nostartfiles -mmcu=atmega2561 ${EXTENSION}.o -o ${EXTENSION}.elf
avr-objcopy --output-target binary ${EXTENSION}.elf ${EXTENSION}.bin
avr-objdump -d ${EXTENSION}.elf > ${EXTENSION}.lst

echo "Test Generator> Copying binary file to /binary codes..."
cp ${EXTENSION}.bin $PWD/"binary codes"
echo "Test Generator> Copying binary file as file_code.bin to processor..."
mv -f ${EXTENSION}.bin $PWD/../file_code.bin


echo "Test Generator> Chosen file: ${EXTENSION}"
echo "Test Generator> Removing ${EXTENSION}.o, ${EXTENSION}.elf, ${EXTENSION}.bin and ${EXTENSION}.lst ..."
rm ${EXTENSION}.o
rm ${EXTENSION}.elf
rm ${EXTENSION}.lst
echo "Test Generator> Temporary test files removed!"


echo "Test Generator> Copying clean data file to processor and /binary data..."
cp -f _clean_data.bin $PWD/../file_data.bin
cp -f _clean_data.bin $PWD/"binary data"/${EXTENSION}_in.bin

fi
