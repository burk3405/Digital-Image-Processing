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
        while (!file.eof()) {
            file.read((char *) &buf, 1);
            outp.write((char *) &buf, 1);
        } //end while
        
        cout << endl;
        cout << "Done writing the file to screen. Goodbye my friend.\n";
    }   
    else cout << "Unable to open file" << endl;
    return 0;
}
