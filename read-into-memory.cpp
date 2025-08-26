// read a file into memory
#include <iostream> // std::cout
#include <fstream> // std::ifstream
using namespace std;

int main() {
    ifstream is("example3.txt", ios::in | ios::binary);
    
    if (is) {
        // get length of file:
        is.seekg(0, is.end);
        int length = is.tellg();
        is.seekg(0, is.beg); // set to the begining.
    
    
        // allocate memory:
        char * buffer = new char[length];
    
        // read data as a block:
        is.read(buffer, length);
        
        is.close();
        
        // print content:
        cout.write(buffer, length);
        delete[] buffer;
    }
    
    return 0;
}
