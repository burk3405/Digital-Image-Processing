#include <iostream> // Creating a text file as a binary file
#include <fstream>
using namespace std;

char memb1[] = "This is a line\n";
char memb2[] = "This is another line\n";
char memb3[] = "This is another line too.";

int main() {
  ofstream filehandle("example2.txt", ios::out | ios::binary);
  if (filehandle.is_open())
  {
    // -1 to Exclude null term
    filehandle.write((char *)&memb1, sizeof(memb1)-1); //Writing contents at that address at that size
    filehandle.write((char *)&memb2, sizeof(memb2)-1);
    filehandle.write((char *)&memb3, sizeof(memb3)-1);
    filehandle.close();
  }
  else cout << "Unable to open file";
  
  return 0;
}
