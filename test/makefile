all: test_main.o
	g++ -o build -pthread -lgtest test_main.o

test_main.o:
	g++ -c -o test_main.o ./test_src/test_main.cpp 
