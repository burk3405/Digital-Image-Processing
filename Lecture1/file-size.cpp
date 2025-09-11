// obtaining file size
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  long begin,end;
  ifstream myfile ("example1.txt");
  begin = myfile.tellg();
  myfile.seekg (0, ios::end);
  end = myfile.tellg();
  myfile.close();
  cout << "File size is: " << (end-begin) << " bytes.\n";
  
  return 0;
}

// /n is 1 byte. each character is also 1 byte.
