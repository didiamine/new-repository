prog:main.o depalea.o
	gcc depalea.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -g 
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g
depalea.o:depalea.c
	gcc -c depalea.c -lSDL -lSDL_image -lSDL_mixer -g 
