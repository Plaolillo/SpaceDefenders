test: main.o menu.o gioco.o
	gcc main.o menu.o gioco.o -o test -lncurses

main.o: menu.h main.c
	gcc -c menu.h main.c

menu.o: gioco.h menu.h menu.c
	gcc -c menu.h menu.c

gioco.o: menu.h gioco.h gioco.c
	gcc -c gioco.h gioco.c

clean:
	rm -f *.o
	rm -f *.gch
	rm -f test
	rm *.txt


