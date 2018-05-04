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
    -r|--remove)
    REMOVE="$2"
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
echo "Test Generator> Tests generated!"

avr-as -mmcu=atmega2561 ${EXTENSION}.s -o ${EXTENSION}.o
avr-gcc -nostartfiles -mmcu=atmega2561 ${EXTENSION}.o -o ${EXTENSION}.elf
avr-objcopy --output-target binary ${EXTENSION}.elf ${EXTENSION}.bin
avr-objdump -d ${EXTENSION}.elf > ${EXTENSION}.lst

fi
if [ ! -z "$REMOVE" ]; then
	echo "Test Generator> Chosen file: ${REMOVE}"
	echo "Test Generator> Removing ${REMOVE}.o, ${REMOVE}.elf, ${REMOVE}.bin and ${REMOVE}.lst ..."
	rm ${REMOVE}.o
	rm ${REMOVE}.elf
	rm ${REMOVE}.bin
	rm ${REMOVE}.lst
	echo "Test Generator> Tests removed!"
fi

