
#include "utillity.h"

using namespace std;

template <typename T>
class Vector{
    private:
    T* vec;
    int size;
    int maxsize;

    public:
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
    int getsize(){
        return size;
    }
};

template <typename T>
class Heap{
    private:
    Vector<T> heap;


    void heapup(int index) {
        if (index == 0) return;

        int mom = (index-1) / 2;
        if (heap[index].getvalue() < heap[mom].getvalue()){
            T temp = heap[index];
            heap[index] = heap[mom];
            heap[mom] = temp;
            heapup(mom);
        }
    }

    void heapdown(int index){
        int esq = (2*index)+1;
        int dir = (2*index)+2;
        int menor = index;

        if (esq < heap.getsize() && heap[menor].getvalue() > heap[esq].getvalue())
            menor = esq;
        if (dir < heap.getsize() && heap[menor].getvalue() > heap[dir].getvalue())
            menor = dir;

        if (menor != index) {
            T temp = heap[index];
            heap[index] = heap[menor];
            heap[menor] = temp;
            heapdown(menor);
        }
    }

    public:

    Heap(){}

    void insert(T p){
        heap.push(p);
        heapup(heap.getsize() - 1);
    }

    T pull(){
        if (heap.getsize()==0)
            throw out_of_range("Empty heap.\n");
        
        T min = heap[0];
        heap[0] = heap[heap.getsize() - 1];
        heap.pop();
        heapdown(0);

        return min;
    }

    int size(){
        return heap.getsize();
    }
};