#include "pq.h"

using namespace std;

class Huffman {
    private:
    Huffman *left;
    Huffman *right;
    char content;
    bool leaf;


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
        
    }

    void decompress(fstream input, fstream output){

    }

};