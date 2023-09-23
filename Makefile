PRG=main.exe

GCC=g++

GCCFLAGS=-std=c++17 -O3

VALGRIND_OPTIONS=-s --leak-check=full
DIFF_OPTIONS=-y --strip-trailing-cr --suppress-common-lines

OBJECTS0=AlgorithmSolver.h AlgorithmProblem.h
DRIVER0=AlgorithmSolver.cpp AlgorithmProblem.cpp main.cpp

INPUT_FILES=data0_hospitals.txt data0_residents.txt
OUTPUT_FILE=output.txt
CAPACITY=2

all: run
gcc0:
	echo "compiling program ..."
	$(GCC) -o $(PRG) $(DRIVER0) $(OBJECTS0) $(GCCFLAGS) 
	echo "compiled program"
run: gcc0
	echo "running program ..."
	./$(PRG) $(INPUT_FILES) $(CAPACITY)
	echo "program end"
clean:
	rm -f *.exe *.o $(OUTPUT_FILE)
