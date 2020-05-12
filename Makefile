CC = gcc
OBJ = main

all:
	$(CC) cell.c gameplace.c main.c -o $(OBJ)

clean:
	rm -rf $(OBJ) *.tar.gz *.o  Docs

dist:
	mkdir GameOfLife && cp cell.c cell.h gameplace.c gameplace.h main.c GameOfLife && tar -czvf GameOfLife.tar.gz GameOfLife && rm -rf GameOfLife



docs:
	doxygen
	xdg-open Docs/html/index.html



exec:
	./$(OBJ)
