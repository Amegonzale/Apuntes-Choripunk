// A.cpp archivo c++
// a.out archivo ejecutable
// in archivo de entrada
// out archivo de salida


// comilar
g++ -std=c++17 A.cpp -o a.out
// ejecutar
./a.out
// en una linea
g++ -std=c++17 A.cpp -o a.out && ./a.out


// compilar con informacion para valgrind
g++ -std=c++17 -g A.cpp -o a.out
// ejecutar con valgrind
valgrind -q ./a.out
// en una linea
g++ -std=c++17 -g A.cpp -o a.out && valgrind -q ./a.out
// ejecutar con valgrind y redireccionar la entrada y salida
valgrind -q ./a.out < in > out

