CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = main.cpp Animal.cpp AnimalImpl.cpp AnimalException.cpp
OBJS = main.o Animal.o AnimalImpl.o AnimalException.o
EXE = main.exe
TXT = test_results.txt

.PHONY: all clean rebuild
all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o *.exe *.txt
	@echo "Cleaned up object files and executable."

rebuild: clean all
