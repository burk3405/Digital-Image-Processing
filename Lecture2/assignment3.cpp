// First 25% and Third 25% of a Text File
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
        file.seekg(0, ios::end);    //Seek to the end
        streampos size = file.tellg();  //Tell the location of get pointer
        
        file.seekg(size/4, ios::beg); // Pointer
        
        
        for (int i = 0; i < size/4; i++) {
            file.read((char *) &buf, 1);    // read one character
            cout.write((char *) &buf, 1);   // write one character
        } //end while
        
            for (int i = 0; i < size/4; i++)
                file.read((char *) &buf, 1);
        
        for (int i = 0; i < size/4; i++) {
            file.read((char *) &buf, 1);    // read one character
            cout.write((char *) &buf, 1);   // write one character
        } //end while

        
        cout << endl;
        cout << "Done writing the file to screen. Goodbye my friend.\n";
    }   
    else cout << "Unable to open file" << endl;
    return 0;
}
