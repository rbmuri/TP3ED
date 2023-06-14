#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

class Point {
    public:
    int x;
    int y;

    Point(int a, int b){
        x = a;
        y = b;
    }
    Point(){}

    bool operator==(Point other) {
        return (x == other.x && y == other.y);
    }

    void print(){
        cout << x << " " << y << "\n";
    }
};
/*
class Reta {
    int a;
    int b;
    int c;
    Reta(Point v, Point w){
        
    }
};
*/
