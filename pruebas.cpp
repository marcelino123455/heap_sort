//
// Created by Ce mar on 29/04/2024.
//
#include "heap_sort.h"

int main(){

    vector<int> v1{0, 53, 58, 59, 26, 41, 97, 31};
    vector<int> v2{0,3,5,1,7,10,1,6,9};
    array<int, 8 > a1{0, 53, 58, 59, 26, 41, 97, 31};
    heap<int> h1(v1);
    h1.imprimir_lista();
    h1.heap_sort();
    h1.imprimir_lista();

    heap<int> h2(v2);
    h2.imprimir_lista();
    h2.heap_sort();
    h2.imprimir_lista();



    return 0;
}