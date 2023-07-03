#include "pq.h"

using namespace std;

class Huffman {
    private:
    Huffman *left;
    Huffman *right;
    char content;
    bool leaf;

    Vector<pair<int, char>> mergesort(Vector<pair<int, char>> pts, int a, int b){
        if (a < b){
            int m = a + (b-a)/2; //m = midway
            Vector<pair<int, char>> firsthalf = mergesort(pts, a, m);
            Vector<pair<int, char>> secondhalf = mergesort(pts, m+1, b);

            int size1 = m - a + 1;
            int size2 = b - m;

            pair<int, char> temp1[size1], temp2[size2];

            for (int i = 0; i < size1; i++)
                temp1[i] = firsthalf[a + i];
            for (int j = 0; j < size2; j++)
                temp2[j] = secondhalf[m + 1 + j];

            int i = 0, j = 0, k = a;
            while (i < size1 && j < size2){
                if (temp1[i].first > temp2[j].first){
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

    public:    
    Huffman(){
        left = nullptr;
        right = nullptr;
        leaf = true;
    }

    void compress(fstream input, fstream output){
        char c;
        int ascii[256] = {0};
        while (input >> c){
            ascii[c]++;
        }
        Vector<pair<int, char>> myvec;
    }



    void decompress(fstream input, fstream output){

    }

};