//
// Created by Ce mar on 29/04/2024.
//
#include "heap_sort.h"

int main(){

    vector<int> v1{0, 53, 58, 59, 26, 41, 97, 31};//8
    vector<int> v2{0,3,5,1,7,10,1,6,9};//9
    vector<int> v3{0,2,3,4,5,6,7,8,9,10,11,12,100,13,14,15,16,17,18,19,20};//10


    array<int, 8 > a1{0, 53, 58, 59, 26, 41, 97, 31};
    heap<int, less<>> h1(v1);
    h1.imprimir_lista();
    h1.heap_sort();
    h1.imprimir_lista();

    heap<int,  greater<>> h2(v2);
    h2.imprimir_lista();
    h2.heap_sort();
    h2.imprimir_lista();

    heap<int,  greater<>> h3(v3);
    h3.imprimir_lista();
    h3.heap_sort();
    h3.imprimir_lista();

    heap<int,  less<>> h4(v3);
    h4.imprimir_lista();
    h4.heap_sort();
    h4.imprimir_lista();



    return 0;
}