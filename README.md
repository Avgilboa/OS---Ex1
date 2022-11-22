# OS---Ex1
Q.1 - Examples

Script started on 2022-11-15 20:29:57+02:00

 ./cmp file1.txt file2.txt
 
Not identical

./cmp file1.txt

Usage : cmp < file1 > < file2 >

exit

Script done on 2022-11-15 20:30:34+02:00 [COMMAND_EXIT_CODE="1"]


Q.2 - Examples

Script started on 2022-11-14 11:26:11+02:00

./copy ptr.txt file1.txt

file link is copied

./copy -l ptr.txt file1.txt

file is copied

exit

Q.3 - Examples

Script started on 2022-11-16 08:58:40-08:00 [TERM="xterm-256color" TTY="/dev/pts/0" COLUMNS="111" LINES="5"]
make
gcc -o cmp cmp.c
gcc -o copy copy.c
gcc -o libcodec1.so -shared -fPIC codec1.c
gcc -o libcodec2.so -shared -fPIC codec2.c
gcc encode.c -ldl -o encode
export LD_LIBRARY_PATH=.
gcc decode.c -ldl -o decode
export LD_LIBRARY_PATH=.
./encode codec1.c HELLOworld
helloworld
./encode codec1 44457HEL^LOworld12
44457hel^loworld12
exit

Script done on 2022-11-16 08:59:54-08:00 [COMMAND_EXIT_CODE="0"]



    Script started on 2022-11-16 09:01:01-08:00 [TERM="xterm-256color" TTY="/dev/pts/0" COLUMNS="111" LINES="5"]
    ./decode codec1 55HEL21LOworld11
    55HEL21LOWORLD11


    Script done on 2022-11-16 09:01:14-08:00 [COMMAND_EXIT_CODE="0"]



we use codes from the some sources:
1. open and close files - from leacture 1
2. open the library function inside the c code - from the man page of dlsym.
3. stat and realink from the man page.
