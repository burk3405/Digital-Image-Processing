#include <iostream>
using namespace std;
int main()
{
// Creation of 1-D dynamic Array
int* p;
int n;
cout << "Enter the dimension of the array ";
cin >> n;
// create 1-d array
p = new int[n];
//create data for 1-d array
srand(time(0)); //used for random number seek value
for (int i = 0; i < n; i++)
    p[i] = rand() % 100;
//Display the contents of the array
cout << endl;
for (int i = 0; i < n; i++)
cout << p[i] << " ";
return 0;
}
