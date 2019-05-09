prog:main.o initialiser.o
	gcc initialiser.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc  -c main.c -lSDL -lSDL_image -lSDL_mixer -g 
initialiser.o:initialiser.c
	gcc -c initialiser.c -lSDL -lSDL_image -lSDL_mixer -g
