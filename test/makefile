all: test_main.o
    g++ -o build -pthread -lgtest_main -lgtest test_main.o

test_main.o:
    g++ -o test_main.o ./test_src/test_main.cpp 
