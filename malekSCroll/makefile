prog:*.h *.c
	gcc *.h *.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lm  -o scroll -g
mainscroll.o:mainscroll.c
	gcc -c mainscroll.c -g
scroll.o:scroll.c
	gcc -c scroll.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f scroll
