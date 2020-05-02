CC = gcc
OBJ = main

all:
	$(CC) cell.c gameplace.c main.c -o $(OBJ)

clean:
	rm -rf $(OBJ)

exec:
	./$(OBJ)
