//
// Created by Ce mar on 29/04/2024.
//

#ifndef TAREA_1_HEAP_SORT_H
#define TAREA_1_HEAP_SORT_H


#include <queue>
#include <vector>
#include <deque>
#include <functional>
#include <iostream>
using namespace std;

template<typename T, typename Compare=std::less<T>,template <typename ...> class Container=std::vector >
class heap{
private:
public:

    Container<T> data;
    Compare cmp;
    int size_s;

    int getLeft(int i){
        return i*2;
    }
    int getRight(int i){
        return ((i*2)+1);
    }

    int getParent(int i_left){
        return i_left/2;
    }


    bool is_root(int index){
        return index == 1;
    }

    bool has_children_left(size_t parent_index) {
        auto left_index_calculate = getLeft(parent_index);
        return left_index_calculate < size_s;
    }

    bool has_right_child(size_t parent_index) {
        return getRight(parent_index) < size_s;
    }

    int get_child_2(int parent_index){
        int left_i = getLeft(parent_index);
        int rigth_i = getRight(parent_index);
        if(has_right_child(parent_index)){
            if(cmp(data[left_i], data[rigth_i])){
                return rigth_i;
            }
        }
        return left_i;
    }
    int get_child(int i){
        auto left_index = getLeft(i);
        if (has_right_child(i)) {
            auto right_index = getRight(i);
            return cmp(data[right_index], data[left_index]) ? left_index : right_index;
        }
        return left_index;
    }

    void percolateDown(int index){//padre
        if (!has_children_left(index)){
            return;
        }
        int child_mayor_menor_compare = get_child(index);
        if(cmp(data[child_mayor_menor_compare], data[index])){
            return;
        }
        swap(data[child_mayor_menor_compare], data[index]);
        percolateDown(child_mayor_menor_compare);


    }

    void heapify(int index){ // Es decir le mandas todo el container para hipifapearlo
        int i_parent = getParent(index);
        while (i_parent>=1){
            percolateDown(i_parent); // T(n) = log(n)
            i_parent--;
        }

    }

//    heap():data(1){}
    int size() { return data.size() - 1; } //Tamaño total

    void heap_sort(){
        heapify(size_s-1);
//        cout<<"size_s:"<<size_s<<endl;
//        cout<<"heapify: ";imprimir_lista();

        while (size_s>=2){ //>1
            swap(data[1],data[size_s-1]);
//            cout<<"swap: ";imprimir_lista();
            size_s--;
            percolateDown(1);
        }




    }

    void imprimir_lista(){
        for(int i =1; i<data.size();i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    heap(Container<T> &c): data(c), size_s(c.size())  {//Darle con nada en el index 0

    }



};


//Especailizacion


#endif //TAREA_1_HEAP_SORT_H
