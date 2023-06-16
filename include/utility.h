#include "datastructures.h"

using namespace std;


//retorna o quadrado da
//distancia de dois pontos
int sqdist(Point a, Point b){
    return (a.x - b.x) * (a.x - b.x) +
           (a.y - b.y) * (a.y - b.y);
}

//retorna 1 se o ponto c estiver em sentido
//horario em relaçao a reta ab, -1 se estiver
//em sentido anti-horário, e 0 se for colinear
int clockwise(Point a, Point b, Point c){
     int area = ( (b.x - a.x) * (c.y - b.y) ) -
                ( (b.y - a.y) * (c.x - b.x) );

     if (area<0) return (+1);
     if (area>0) return (-1);

     return (0);
}

float angle(Point a, Point b){
    if ( (b.y - a.y) == 0 ) return atan(INF); 
    float res = static_cast<float>(b.x - a.x) / (b.y - a.y);
    return atan(res);
}

//retorna aquele que está mais 
//a direita de a, entre b e c
Point comparison(Point a, Point b, Point c){
    int temp = clockwise(a, b, c); 
    if (temp== +1){
        return c;
    }
    if (temp== -1){
        return b;
    }
    else {
        if ( sqdist(a, b) > sqdist(a, c) ) 
                return b;            
        else return c;
    }
}


//retorna o ponto de menor y
//(em empate, olha o x tambem)
Point lowestpoint(Pointvector pts){
    
    Point pt = pts[0];
    for (int i = 1; i< pts.size; i++){
        if (pt.y > pts[i].y) 
            pt = pts[i];
        
        if (pt.y == pts[i].y)
            if (pt.x > pts[i].x) 
                pt = pts[i];   
    }
    return pt;
}

//retorna o index do ponto de menor y
int lowestpointindex(Pointvector pts){
    int res=0;
    Point pt = pts[0];
    for (int i = 1; i< pts.size; i++){
        if (pt.y > pts[i].y){ 
            pt = pts[i];
            res = i;
        }
        if (pt.y == pts[i].y)
            if (pt.x > pts[i].x){ 
                pt = pts[i];   
                res = i;
        }
    }
    return res;
}