#---------------------------------------------------------------------
# Arquivo		: Makefile
# Conteúdo	: Compilar o programa
# Autor			: André Luiz Alves Costa (andrelac963@gmail.com)
# Histórico	: 2023-00-00 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo e executa exemplo
#					: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/teste.o 
HDRS = $(INC)/teste.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

all:  $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/teste.o: $(HDRS) $(SRC)/teste.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/teste.o $(SRC)/teste.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out