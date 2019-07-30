CC=gcc
STD=-std=gnu99
FLAG=-Wall -Werror
OBJ=school1.o all.o school2.o master.o teacher.o student.o
BIN=test 

all:$(OBJ)
	$(CC) $(OBJ) -o $(BIN)
%.o:%.c
	$(CC) $(FLAG) -c $<

clean:
	rm $(OBJ) $(BIN)
