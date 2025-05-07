CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = ./src/main.cpp ./src/animal/Animal.cpp ./src/animal/exception/AnimalException.cpp
OBJS = $(SRCS:./src/%.cpp=./build/%.o)
EXE = main.exe

.PHONY: all clean rebuild docs

all: $(EXE)

$(EXE): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $^

./build/%.o: ./src/%.cpp
	mkdir -p "$(dir $@)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

docs:
	doxygen Doxyfile
	cd latex && make
	@echo "Documentation generated in the docs directory."

clean:
	rm -rf ./build $(EXE) ./docs *.bin
	@echo "Cleaned up build files and output."

rebuild: clean all
