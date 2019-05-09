prog: main.o initafficheobj.o
	gcc initafficheobj.o main.o -lSDL -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g
initafficheobj.o:initafficheobj.c
	gcc -c initafficheobj.c -lSDL -lSDL_image -g
