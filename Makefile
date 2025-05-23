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
	@doxygen Doxyfile
	@cd "docs/latex" && make
	@echo "Running in: $$(pwd)"
	@cp "docs\latex\refman.pdf" "documentation.pdf"

	@echo "Documentation generated in the docs directory."

clean:
	rm -rf ./build $(EXE) ./docs *.bin documentation.pdf
	@echo "Cleaned up build files and output."

rebuild: clean all
