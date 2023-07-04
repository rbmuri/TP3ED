#include "huffman.h"

using namespace std;


int main(){
    cout << "Main entered.\n";
    string teste;
    fstream file;

    file.open("test");
    file >> teste;
    cout << teste << endl;
    file.close();
 
    //string str = get_bits("test");
    //cout << str; 
    write_bits("teste", "00110011001100110011001000110100");
    get_bits("teste");

    return 0;
}