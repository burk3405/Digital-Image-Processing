// Creation of 2-D Dynamic Array and writing
// 1 0 1 0 10 and 0 1 0 1 to each consecutive row
// Like a chess board
//
//---------------------------------
#include <iostream>
using namespace std;

int main()
{
  int **X; // For 2-D.     For 1-D, use *X.
  int row, col;
  cout << "Enter the dimensions of the array. That is row and column.";
  cin >> row >> col;
  X = new int* [row];
  for (int i = 0; i < row; i++)
  X[i] = new int[col];
  
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (i % 2) {
        if (j % 2)
          X[i][j] = 1;
        else
          X[i][j] = 0;
      }
      else {
        if (j % 2)
          X[i][j] = 0;
        else
          X[i][j] = 1;
      }
  
  //Display data
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++)
      cout << X[i][j] << " ";
      cout << endl;
  }
  
  return 0;
}
