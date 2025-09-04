// First 25% and Last 25% of Text File
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

int main() {
    
    char buf; //character array.
    ifstream file("test.txt", ios::in | ios::binary);
    ofstream outp("copied.txt", ios::out | ios::binary);
    
    if (file.is_open())
    {
        file.seekg(0, ios::end);
        streampos size = file.tellg();
        
        file.seekg(size/4, ios::beg);
        
        
        for (int i = 0; i < 2*size/4; i++) {
            file.read((char *) &buf, 1);    // read one character
            cout.write((char *) &buf, 1);   // write one character
        } //end while

        
        cout << endl;
        cout << "Done writing the file to screen. Goodbye my friend.\n";
    }   
    else cout << "Unable to open file" << endl;
    return 0;
}
