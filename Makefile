.PHONY: main

obj: main.cpp Animal.cpp
	g++ -c main.cpp Animal.cpp

exe: main.o Animal.o
	g++ -o main.exe main.o Animal.o

all:
	obj exe

clean:
	rm -f main.o

rebuild: clean all
