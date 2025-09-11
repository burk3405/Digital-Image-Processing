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
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < n; j++)
			wf << (char)0 << (char)0 << (char)255;
	for (int i = 16; i < 784; i++) {
		//Left 16 Columns
		for (int j = 0; j < 16; j++)
			wf << (char)0 << (char)0 << (char)255;
		if (((i - 16) / 96) % 2) {
			for (int j = 16; j < 784; j += 96) {
				if (inner)
					for (int a = 0; a < blok; a++)
						wf << (char)255 << (char)0 <<
						(char)0;
				else for (int a = 0; a < blok; a++)
					wf << (char)0 << (char)255 << (char)0;
				if (inner) inner = 0;
				else inner = 1;
			}
		}
		else {
			for (int j = 16; j < 784; j += 96) {
				if (outer)
					for (int a = 0; a < blok; a++)
						wf << (char)255 << (char)0 <<
						(char)0;
				else for (int a = 0; a < blok; a++)
					wf << (char)0 << (char)255 << (char)0;
				if (outer) outer = 0;
				else outer = 1;
			}
		}
		//Right 16 Columns
		for (int j = 784; j < n; j++)
			wf << (char)0 << (char)0 << (char)255;
	}
	//Bottom 16 rows
	for (int i = 784; i < n; i++)
		for (int j = 0; j < n; j++)
			wf << (char)0 << (char)0 << (char)255;
	cout << "Done" << endl;
	system("pause");
	return 0;
}
