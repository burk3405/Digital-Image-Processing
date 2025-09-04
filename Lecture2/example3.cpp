// read a file into memory and write it to screen, block by block
#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

int block = 10;

int main() {
    int size, iteration, remain;
    char memblock[10]; // character array
    ifstream file("example.txt", ios::in | ios::binary);
    if (file.is_open())
    {
        file.seekg(0, ios::end); //seek to the end
        size = file.tellg(); //tell the location of get pointer
        
        file.seekg(0, ios::beg); // pointer to the beginning of file.
        iteration = size / block; // Number of iterations
        remain = size % block; // Any remaining characters

        while (iteration > 0) {
            file.read(memblock, block); // read the file block by block
            cout.write(memblock, block); // write block of characters
            iteration--;
        } //end while

        if (remain > 0) { // if there is any unread data
        file.read(memblock, remain); // read the rest of characters.
        cout.write(memblock, remain);
        }//end if

    cout << endl;
    cout << "Done writing the file to screen. Good Bye \n";
    }
    
else cout << "Unable to open file" << endl;
return 0;
}
