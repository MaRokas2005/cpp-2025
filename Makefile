.PHONY: main

main: gyvunas.cpp
	g++ -o gyvunas.exe gyvunas.cpp
	./gyvunas.exe

clean:
	rm -f gyvunas.exe
