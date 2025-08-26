#include <iostream>
using namespace std;
int main()
{
int X[6][5];
srand(time(0)); // Uses the random library to randomize the output. Optional!
for (int i = 0; i < 6; i++)
    for (int j=0;j < 5; j++)
        X[i][j] = rand() % 100;
for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 5; j++)
cout << X[i][j] << " ";
cout << endl;
}
return 0;
}
