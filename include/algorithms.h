#include "sorting.h"

using namespace std;

Pointvector jarvis(Pointvector pts){
    Pointvector hull;

    hull.push(lowestpoint(pts));
    
    int i = 1;
    while (1){
            hull.push(pts[i-1]);
        for (int j=0; j<pts.size; j++){
            hull[i] = comparison(hull[i-1], hull[i], pts[j]);
        }
        if (hull[0]==hull[i]) {
            hull.pop();
            break;
        }
        i++;
    }
    return hull;
}

//Recebe um Pointvector pts que terá seu fecho retornado, e um
//inteiro sort_type que define o método de ordenaçao a ser usado  
// sort_type = 1: insertion
// sort_type = 2: merge
// sort_type = 3: bucket
Pointstack graham(Pointvector pts, int sort_type){
    pts = sort(pts, sort_type);
    
    Pointstack stack;
    stack.place(pts[0]);
    stack.place(pts[1]);
    for (int i=2; i<pts.size; i++){
        //cout << "clockwise = " << clockwise(stack.beforetop(), stack.top(), pts[i])
        //<< " (" << i << "): \n";
        //stack.beforetop().print();
        //stack.top().print();
        //pts[i].print();
        while ( clockwise(stack.beforetop(), stack.top(), pts[i]) != -1){
            
            stack.pop();
        }
        
        stack.place(pts[i]);  
           
    }
    if (clockwise(stack.beforetop(), stack.top(), pts[0]) == 0){
            stack.pop();
        }
    return stack;
}

