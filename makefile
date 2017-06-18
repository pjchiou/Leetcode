#A simple makefile

#declaration
CC=g++
FLAGS=-g -Wall

all:main.cpp
	$(CC) main.cpp -o main.out

clean:
	rm -f main.out
