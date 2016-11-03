lib: mylib.cpp
	gcc -shared -o mylib.so mylib.cpp

main: main.cpp
	gcc -o main main.cpp -L. mylib.so