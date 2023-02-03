DEP=base64.cpp

all:
	g++ main.cpp $(DEP) -o main

run:
	./main

encode:
	@g++ main.cpp $(DEP) -o main
	./main --encode "hello, world!"

decode:
	@g++ main.cpp $(DEP) -o main
	./main --decode "bWFyY28gYXVyZWxpbyBsaW1hIA=="
