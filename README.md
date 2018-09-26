# Virtual Atmega2561 emulator
Emulator of Atmega2561 selected instructions written in C.
Implemented instructions:
- LDI
- MOV
- FMUL
- FMULS
- FMULSU
- ELPM
- EIJMP
- EICALL
- IJMP
- RJMP
- LDD
- STD

## Creating Unit Tests:
1. Create file with assembly instructions (file with .s extension) and put it into "/tests" folder
2. Follow the "make-test.sh" instructions written below
3. Follow the "compare.sh" instructions written below
4. Generated .hex files will showcase the functionality of the instructions.

### Using the make-test.sh script:
1. Write "./make-test.sh -f filename" (filename without the extension)
2. Run the emulator ("./syko.exe" with apropriate arguments)
3. Copy the output file (file_data.bin) to "tests/binary data" and rename it to "name_out.bin" where name is the name of the test

### Using the compare.sh script:
1. Run "./compare.sh" inside the folder "binary data", there will be created two output files: .dec i .hex

## Using the test-all.sh script"
This script runs for each .s test file inside /tests/
It does the following:
1. Runs the make-test.sh script and creates adequate binary files
2. Runs syko.exe with arguments: 30 30 zeroPC
3. Copies output files (file_data.bin) to /tests/binary data with adequate name
4. Runs compare.sh script and creates comparison .hex and .dec files

To run it write ". ./test-all.sh" in terminal from "/tests/" folder
