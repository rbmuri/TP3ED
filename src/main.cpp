
#include "algorithms.h"

using namespace std;


int main(){
    fstream input;
    string fecho, file;
    clock_t t0, t1, t2, t3, t4, t5;
    
    while (1){
        cin >> fecho;
        if (fecho!="fecho") return 1;
        if (fecho=="fecho") 
    {
    cin >> file;
    
    input.open(file);
    Point p;
    Pointvector pts, jv, gi, gm, gb;
    while (1){
        input >> p.x >> p.y;

        if (input.eof()) break;

        pts.push(p);
    }
    
    jv = pts;
    gi = pts;
    gm = pts;
    gb = pts;
   
    t1 = clock();
    Pointstack grahammerge = graham(gm, 2);
    //t1 = clock() - t1;
    t2 = clock();
    Pointstack grahaminsert = graham(gi, 1);
    //t2 = clock() - t2;
    t3 = clock();
    Pointstack grahambucket = graham(gb, 3);
    //t3 = clock() - t3;
    t4 = clock();
    Pointvector jarvishull = jarvis(pts);
    //t4 = clock() - t4;
    t5 = clock();
    
    cout << "\nFECHO CONVEXO:\n";
    jarvishull.print();
    cout << endl;

    printf("GRAHAM+MERGESORT: %.3fs\n", double(t2-t1) / CLOCKS_PER_SEC);
    printf("GRAHAM+INSERTIONSORT: %.3fs\n", double(t3-t2) / CLOCKS_PER_SEC);
    printf("GRAHAM+BUCKETSORT: %.3fs\n", double(t4-t3) / CLOCKS_PER_SEC);
    printf("JARVIS: %.3fs\n", double(t5-t4) / CLOCKS_PER_SEC);
    cout << endl;
    input.close();
    }
    }
    return 0;
}