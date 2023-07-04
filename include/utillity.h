#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <bitset>

using namespace std;

string get_bits(string path) {
    fstream input;
    input.open(path, ios::binary);
    string str = "";
    char c;
    //cout << "break!\n";
    while (input >> c){ //input.get(c) might work better
    //cout << "break!\n";
    for (int b = 7; b>=0; b--){
        if ( (c >> b) & 1 ) str = str + "1";
        else str = str + "0";
    }}
    return str;
}

void write_bits(string path, string str){
    fstream output;
    output.open(path, ios::binary);
    cout << "break!\n";
    while (str.size()%8 != 0) str = str + '0';cout << "break! \n"; 
    cout << "break!\n";
    for (int i = 0; i < str.size(); i+=8){
        cout << "break!1\n";
        unsigned char byte = bitset<8>( str.substr( i, 8)).to_ulong();
        cout << "break!2\n";
        cout << byte << endl;
        output.write(reinterpret_cast<char*>);
        cout << "break!3\n";
    }
}