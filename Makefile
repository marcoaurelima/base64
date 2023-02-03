DEP=base64.cpp

all:
	g++ main.cpp $(DEP) -o main

run:
	./main