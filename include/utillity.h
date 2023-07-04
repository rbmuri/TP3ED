#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <bitset>

using namespace std;

string get_bits(string path) {
    fstream input;
    input.open(path, fstream::in | fstream::binary);
    string str = "";
    char c;
    int i=0;
    //cout << "break!\n";
    while (input >> c){ //input.get(c) might work better
    //cout << "break!\n";
    cout << c << "->";
    i++;
    cout << i << ":";
    for (int b = 7; b>=0; b--){
        if ( (c >> b) & 1 ) {str = str + "1"; cout << "1";}
        else {str = str + "0"; cout << "0";}
    }
    cout << endl;
    }
    return str;
}

void write_bits(string path, string str){
    fstream output;
    output.open(path, fstream::out | fstream::binary);
    
    while (str.size()%8 != 0) str = str + '0';
    if (!output.is_open()) { cout << "Error in opening.\n"; } 
    else { cout << "File opened!\n"; }
    for (int i = 0; i < str.size(); i= i+8){
        bitset<8> byte;
        for (size_t j = 0; j < 8; j++) {
            if (str.substr(i, 8)[j] == '1') {
                byte.set(7 - j, 1);  // Set the corresponding bit to 1
            }
        }

        // Write the binary data to the file
        output.write(reinterpret_cast<char*>(&byte), sizeof(byte)/8);
        

    }
}