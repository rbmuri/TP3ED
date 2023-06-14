#include <bits/stdc++.h>
#include "algorithms.h"

using namespace std;


int main(){
    int size; 

    cin >> size;
    Pointvector pts;
    for (int i = 0; i< size; i++){
        Point temp;
        cin >> temp.x >> temp.y;
        pts.push(temp);
    }
    cout << "Lowest point: ";
    lowestpoint(pts).print();
 
    cout << "Comparison: ";
    comparison(pts[0], pts[1], pts[2]).print();

    cout << "Angle: ";
    cout << angle(pts[0], pts[1]) << endl;

    cout << "Clockwise: ";
    cout << clockwise(pts[0], pts[1], pts[2]) << endl;

    cout << "Square distance: ";
    cout << sqdist(pts[0], pts[1]) << endl;

    cout << "Jarvis: \n";
    Pointvector pts2 = jarvis(pts);


    for (int i = 0; i< pts2.size; i++){
        pts2[i].print();
    } 
    Pointvector pts4 = sort(pts, 3);

    cout << "sorted: \n"; 
    for (int i = 0; i< pts4.size; i++){
        pts4[i].print();
    }
    
    cout << "pts: \n"; 
    for (int i = 0; i< pts.size; i++){
        pts[i].print();
    } 
    cout << "Graham: \n";
    Pointstack pts3 = graham(pts);
    pts3.print();
    

    //cout << comparison(c, a, b).x << " " << comparison(c,a,b).y;
    return 0;
}