#include<iostream>
#include<fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
	ofstream wf("outbin.ppm", ios::out | ios::binary);
	string header = "P6 800 800 255 ";
	wf << header << endl;
	int outer = 0, inner = 1;
	int n, blok;
	n = 800;
	blok = 96;
	//Upper 16 rows
	//matrix for first channel
	int** in_matrix_ch1 = new int* [n];
	for (int i = 0; i < n; ++i)
		in_matrix_ch1[i] = new int[n];
	//matrix for second channel
	int** in_matrix_ch2 = new int* [n];
	for (int i = 0; i < n; ++i)
		in_matrix_ch2[i] = new int[n];
	//matrix for thrid channel
	int** in_matrix_ch3 = new int* [n];
	for (int i = 0; i < n; ++i)
		in_matrix_ch3[i] = new int[n];
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < n; j++)
		{
			in_matrix_ch1[i][j] = (int)128;
			in_matrix_ch2[i][j] = (int)128;
			in_matrix_ch3[i][j] = (int)128;
		}
	for (int i = 16; i < n - 16; i++) {
		////Left 16 Columns
		for (int j = 0; j < 16; j++) {
			in_matrix_ch1[i][j] = (int)128;
			in_matrix_ch2[i][j] = (int)128;
			in_matrix_ch3[i][j] = (int)128;
		}
		if (((i - 16) / 96) % 2) {
			for (int j = 16; j < 784; j += 96) {
				if (inner)
					for (int a = 0; a < blok; a++) {
						in_matrix_ch1[i][j + a] = (int)255;
						in_matrix_ch2[i][j + a] = (int)0;
						in_matrix_ch3[i][j + a] = (int)0;
					}
				else
					for (int a = 0; a < blok; a++) {
						in_matrix_ch1[i][j + a] = (int)0;
						in_matrix_ch2[i][j + a] = (int)0;
						in_matrix_ch3[i][j + a] = (int)255;
					}
				if (inner) inner = 0;
				else inner = 1;
			}
		}
		else {
			for (int j = 16; j < 784; j += 96) {
				if (outer)
					for (int a = 0; a < blok; a++) {
						in_matrix_ch1[i][j + a] = (int)255;
						in_matrix_ch2[i][j + a] = (int)0;
						in_matrix_ch3[i][j + a] = (int)0;
					}
				else
					for (int a = 0; a < blok; a++) {
						in_matrix_ch1[i][j + a] = (int)0;
						in_matrix_ch2[i][j + a] = (int)0;
						in_matrix_ch3[i][j + a] = (int)255;
					}
				if (outer) outer = 0;
				else outer = 1;
			}
		}
		//Right 16 Columns
		for (int j = 784; j < n; j++) {
			in_matrix_ch1[i][j] = (int)128;
			in_matrix_ch2[i][j] = (int)128;
			in_matrix_ch3[i][j] = (int)128;
		}
	}
	//Bottom 16 rows
	for (int i = 784; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			in_matrix_ch1[i][j] = (int)128;
			in_matrix_ch2[i][j] = (int)128;
			in_matrix_ch3[i][j] = (int)128;
		}
	//Output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			wf << (char)in_matrix_ch1[i][j];
			wf << (char)in_matrix_ch2[i][j];
			wf << (char)in_matrix_ch3[i][j];
		}
	}
	system("pause");
	return 0;
}
