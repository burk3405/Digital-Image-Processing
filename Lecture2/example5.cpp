// Example 5: Writing a binary file one character at a time to the screen.
// read a file into memory and write it to screen, one char at a time
#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
int size;
char buf; // character element, 1 byte
ifstream file("example.txt", ios::in | ios::binary);
if (file.is_open())
{
file.seekg(0, ios::end); //seek to the end
size = file.tellg(); //tell the location of get pointer
file.seekg(0, ios::beg); // pointer to the beginning of file.
while (size) {
file.read((char *) &buf, 1); // read one character
cout.write((char *) &buf, 1); // write one character
size--;
} //end while
cout << endl;
cout << "Done writing the file to screen. Good Bye \n";
}
else cout << "Unable to open file" << endl;
return 0;
}
