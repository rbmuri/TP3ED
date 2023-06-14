#include "geometry.h"

using namespace std;

class Stack{
  private:
    int topo;
    int w[10000];
  public:
    Stack(){
      topo = -1;
    }
    void place(int x){
      topo++;
      w[topo] = x;
    }
    int top(){
      return w[topo];
    }
    int size(){
      return topo+1;
    }
    int pop(){
      topo--;
      return w[topo+1];      
    }
};

class Pointstack{
  private:
    int maxsize;
    int topo;
    Point* w;
  public:
    Pointstack(){
      w = new Point[1];
      topo = -1;
      maxsize = 1;
    }
    void place(Point x){
      if (topo+1==maxsize){
        Point* arr = new Point[2*(topo+1)];
        for (int i=0; i<topo+1; i++){
                arr[i] = w[i];
            }
            maxsize *= 2;
            w = arr;
      }
      topo++;
      w[topo] = x;
    }
    Point top(){
      return w[topo];
    }
    Point beforetop(){
      return w[topo-1];
    }
    int size(){
      return topo+1;
    }
    Point pop(){
      topo--;
      return w[topo+1];      
    }
    void print(){
        for (int i=0; i<topo+1; i++){
            w[i].print();
        }
    }
};

class Pointvector{
    public:
    Point* vec;
    int size;
    int maxsize;

    Pointvector(){
        vec = new Point[1];
        size = 0;
        maxsize = 1;
    }

    void push(Point item){
        if (size==maxsize){
            Point* arr = new Point[2*size];
            for (int i=0; i<size; i++){
                arr[i] = vec[i];
            }
            maxsize *= 2;
            vec = arr;
        }
        vec[size] = item;
        size++;
    }
    void push(Point item, int index){
        if (index>=maxsize){
            Point* arr = new Point[2*index];
            for (int i=0; i<size; i++){
                arr[i] = vec[i];
            }
            maxsize = 2*index;
            vec = arr;
        }
        vec[index] = item;
        
    }
    Point access(int i){
        return vec[i];
    }
    void swap(int i, int j){
        Point temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
    Point& operator[](int a) {
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

