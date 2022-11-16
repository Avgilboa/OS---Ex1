.PHONY: all clean
all: cmp copy lib encode decode
cmp: cmp.c
	gcc -o cmp cmp.c
copy: copy.c
	gcc -o copy copy.c
encode: lib encode.c 
	gcc encode.c -ldl -o encode
	export LD_LIBRARY_PATH=.
decode: lib decode.c
	gcc decode.c -ldl -o decode
	export LD_LIBRARY_PATH=.
lib: codec1.c codec2.c codec.h 
	gcc -o libcodec1.so -shared -fPIC codec1.c
	gcc -o libcodec2.so -shared -fPIC codec2.c
		
clean:
	rm encode decode cmp copy libcodec1.so libcodec2.so 2>/dev/null