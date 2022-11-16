.PHONY: all clean
all: task1 task2 task3 lib
task1: cmp.c
	gcc -o cmp cmp.c
task2: copy.c
	gcc -o copy copy.c
task3: lib encode.c encode.c 
	gcc encode.c -ldl -o encode
	gcc encode.c -ldl -o decode
lib: codec1.c codec2.c codec.h
	gcc -o libcodec1.so -shared -fPIC codec1.c
	gcc -o libcodec2.so -shared -fPIC codec2.c
clean:
	rm encode decode cmp copy libcodec1.so libcodec2.so 2>/dev/null