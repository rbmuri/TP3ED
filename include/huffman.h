#include "heap.h"

using namespace std;

class Huffman {
    private:
    Huffman *left;
    Huffman *right;
    char content;
    int value;
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
    int getvalue(){
        return value;
    }
    char getcontent(){
        return content;
    }
    

    Huffman(int v, char c){
        left = nullptr;
        right = nullptr;
        leaf = true;
        content = c;
        value = v;
    }

    Huffman(Huffman l, Huffman r, int v){
        left = &l;
        right = &r;
        leaf = false;
        content = 0;
        value = v;
    }

    Huffman(){
        left = nullptr;
        right = nullptr;
        leaf = true;
    }

    string encode_structure(){
        if (leaf) return "0";
        else {
            return "1" + left->encode_structure() + right->encode_structure();
        }
    }
    string encode_content(){
        if (leaf) return ""+content;
        else {
            return left->encode_content() + right->encode_content();
        }
    }
    /*
    Huffman decode(fstream input){
        char c;
        
    }
    */

    void compress(fstream input, fstream output){
        char c;
        int ascii[256] = {0};
        Heap<Huffman> myheap; 
        while (input >> c){
            ascii[c]++; //collecting frequency of characters
        }
        for (int i=0; i<=128; i++){
            if (ascii[i]==0) continue;
            Huffman h(ascii[i], i);
            myheap.insert(h); //assigning them to a heap
        }
        while (myheap.size()!=1){
            Huffman h1 = myheap.pull(), h2 = myheap.pull();
            int val = h1.getvalue() + h2.getvalue();
            Huffman h(h1, h2, val);
            myheap.insert(h);
        } //trimming down the heap until a binary tree is left
        Huffman fin = myheap.pull(); //extract it
        
        
        string struc = fin.encode_structure(); //
        string cont = fin.encode_content();
        
        

        


        

        input.seekg(0, input.beg);

        
        
        
    }



    void decompress(fstream input, fstream output){
        
    }

};