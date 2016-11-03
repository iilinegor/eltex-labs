main: main.cpp
	gcc -o main main.cpp -ldl

lib: mylib.cpp
	gcc -fPIC -shared -o libmy.so -L. mylib.cpp