# heap: fib_heap.o main.o
# 	g++ main.o fib_heap.o -std=c++1y  -O0 -o main

# main.o: main.cpp 
# 	g++ main.cpp -std=c++11 -O0 -c -g

# fib_heap.o: fib_heap.h fib_heap.cpp
# 	g++ fib_heap.h -std=c++11 -O0 -c -g
run: main
	./main

main: main.cpp fib_heap.h fib_heap.cpp
	g++ main.cpp -std=c++11 -g -o main