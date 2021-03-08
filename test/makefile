all: test_main.o
	g++ -o TestBuild -pthread test_main.o -lgtest 

test_main.o:
	g++ -c -o test_main.o ./test_src/test_main.cpp 
