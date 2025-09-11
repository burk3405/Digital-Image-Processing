#include<iostream>
#include<fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
	ofstream wf("outbin.ppm", ios::out | ios::binary);
	string header = "P6 768 768 255 ";
	wf << header << endl;
	int outer = 1, inner = 1;
	int n, m, blok;
	n = m = 768;
	blok = 96;
	int d1 = 0;
	int d2 = 255;
	for (int i = 0; i < n / blok; i++) {
		if (i % 2) {
			for (int b = 0; b < blok; b++)
				for (int j = 0; j < m / blok; j++) {
					if (j % 2) //Switch every-other row or column
						for (int a = 0; a < blok; a++) {
							wf.write((char*)&d2, 1);
							wf.write((char*)&d1, 1);
							wf.write((char*)&d1, 1);
						}
					else
						for (int a = 0; a < blok; a++) {
							wf.write((char*)&d1, 1);
							wf.write((char*)&d2, 1);
							wf.write((char*)&d1, 1);
						}
				}
		}
		else {
			for (int b = 0; b < blok; b++)
				for (int j = 0; j < m / blok; j++) {
					if (j % 2)
						for (int a = 0; a < blok; a++) {
							wf.write((char*)&d1, 1);
							wf.write((char*)&d2, 1);
							wf.write((char*)&d1, 1);
						}
					else
						for (int a = 0; a < blok; a++) {
							wf.write((char*)&d2, 1);
							wf.write((char*)&d1, 1);
							wf.write((char*)&d1, 1);
						}
				}
		}
	}
	cout << "Done" << endl;
	system("pause");
	return 0;
}
