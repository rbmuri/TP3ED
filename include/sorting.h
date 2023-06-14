#include "utility.h"

using namespace std;

Pointvector insertionsort(Pointvector pts){
    Point key, key2;
    int a, b;
    for (a=2; a<pts.size; a++){
        key = pts[a];
        b = a-1;

        while ( 
                b >= 1 &&
                comparison(pts[0], key, pts[b]) == key
              ) {
            pts[b+1] = pts[b];
            b--;
            }

        pts[b+1] = key;
    }
    return pts;
}



Pointvector mergesort(Pointvector pts, int a, int b){
    if (a < b){
        int m = a + (b-a)/2; //m = midway
        Pointvector firsthalf = mergesort(pts, a, m);
        Pointvector secondhalf = mergesort(pts, m+1, b);

        int size1 = m - a + 1;
        int size2 = b - m;

        Point temp1[size1], temp2[size2];

        for (int i = 0; i < size1; i++)
            temp1[i] = firsthalf[a + i];
        for (int j = 0; j < size2; j++)
            temp2[j] = secondhalf[m + 1 + j];

        int i = 0, j = 0, k = a;
        while (i < size1 && j < size2){
            if (comparison(pts[0], temp1[i], temp2[j]) == temp1[i]){
                pts[k] = temp1[i];
                i++;
            }
            else {
                pts[k] = temp2[j];
                j++;
            }
            k++;
        }
        while (j < size2) {
        pts[k] = temp2[j];
        j++;
        k++;
        }
        while (i < size1) {
        pts[k] = temp1[i];
        i++;
        k++;
        }
    }
    return pts;
}

Pointvector sort(Pointvector pts, int sort_type);

Pointvector bucketsort(Pointvector pts){
    int size = pts.size;
    Pointvector buckets[size];
    Pointvector res;
    res.push(pts[0]);
    
    for (int i = 1; i<size; i++){
        
        int b = (size-1) * 
        (1-(angle(pts[0], pts[i]) + M_PI/2 ) / M_PI);
        
        buckets[b].push(pts[i]);
    }
    
    for (int i = 0; i< size; i++){
        mergesort(buckets[i], 0, buckets[i].size -1);
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < buckets[i].size; j++){
            res.push(buckets[i][buckets[i].size-1-j]);
        }
    }
    
    return res;
}

//Recebe um Pointvector pts que será ordenado, e um
//inteiro sort_type que define o método a ser usado  
// sort_type = 1: insertion
// sort_type = 2: merge
// sort_type = 3: bucket
Pointvector sort(Pointvector pts, int sort_type){
    int index = lowestpointindex(pts);
    pts.swap(0, index);
    if (sort_type==1)
        return insertionsort(pts);
    if (sort_type==2)
        return mergesort(pts, 1, pts.size -1);
    if (sort_type==3)
        return bucketsort(pts);
    
    
}