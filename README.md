# OS---Ex1---Files
Examples how to run the functions.

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

----------------------------------------------------------------------------------
EXERCISES OS  COURSE – 1
* I will use MOSS to check for copied work.
* To be submitted by 22/11/22 23:59:59

* There will be new exercise next week!

* Please provide all files in a single gziped tar. 

* You must submit 9 files in your tgz (Makefile, encode.c, decode.c, codec1.c codec2.c codec.h, cmp.c , copy.c, README)

* Make all must make all binaries. 

* Make clean must delete all craft

* Please include README with
1. Two usage examples. (use script(1)) 
2. Exact location (URL) of any internet code that you have used in your exercise 

**** Using the web is legal but if two students are using the same web location this will trigger MOSS.

**** copying is not allowed. citing without reference is either copying (and thus not allowed) or violation of this instruction and THERE WILL BE GRADE DEDUCTION

* Additional submission instruction and submission box will be created by the grader


Linux practice

1.	Write a compare file program. Use FILE * API to read and compare the files.

<Usage : cmp <file1> <file2

Output : “Identical\n” or “Not identical\n or “Usage : cmp <file1> <file2>”. 

2.	Write a copy file program. Use file descriptor API (open(2), read(2), write(2), close(2)) 

Usage : copy <file1><file2>

Output : file is copied. Or “Usage : copy <file1> <file2>”.

3.	Support copying of symbolic links in copy. Use -l to copy link contents. Without -l copy the file linked by the symbolic link. Use readlink(2), stat(2), getopt(3)

note: -l means lower case 'L'

4.	Support enoding the file using codec library. Code two simple encoders.

Each encoderlib has two funcs 

a.	int encode(char * src, char * dst, int len)

b.	int decode(char * src, char * dst, int len)

codec1.so : Encoder converts uppercase chars to lowercase and vise versa. Doesn’t change all other chars.

codec2.so : Encoder calculates NEG value of each char.

for NEG look here


Use : dleopen(3), dlsym(3), dlclose(3) to open libraries

Use : isalpha(3), toupper(3), tolower(3) for codec1

Use : gcc –shared to compile libraries


Output the encoded string.


Your Makefile must provide at least four binaries (after make all) : encode and decode as well as the two codecs shared object.


 :Usage

encode <codec> <message>

Output : encoded message

decode <codec><encoded message>

Output : message

Example:  ./encode codec1 LALALA123

Output : lalala123