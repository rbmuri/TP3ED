#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

template <typename T>
class Vector{
    public:
    T* vec;
    int size;
    int maxsize;

    Vector(){
        vec = new T[1];
        size = 0;
        maxsize = 1;
    }

    void push(T item){
        if (size==maxsize){
            T* arr = new T[2*size];
            for (int i=0; i<size; i++){
                arr[i] = vec[i];
            }
            maxsize *= 2;
            vec = arr;
        }
        vec[size] = item;
        size++;
    }
    void push(T item, int index){
        if (index>=maxsize){
            T* arr = new T[2*index];
            for (int i=0; i<size; i++){
                arr[i] = vec[i];
            }
            maxsize = 2*index;
            vec = arr;
        }
        vec[index] = item;
        
    }
    T access(int i){
        return vec[i];
    }
    void swap(int i, int j){
        T temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
    T& operator[](int a) {
        return vec[a];
    }
    void pop(){
        size--;
    }
    void print(){
        for (int i=0; i<size; i++){
            vec[i].print();
        }
    }
};