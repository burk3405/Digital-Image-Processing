#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char* argv[]) {
	ofstream wf("outbin.ppm", ios::out | ios::binary);

	string header = "P6 768 768  255 ";
	// header = header + '\n';	// This line is irrelevant because of line 11
	wf << header << endl;

	int outer = 1, inner = 1;
	int n, m, blok;
	n = m = 768;
	blok = 96;

	int d1 = 255;
	int d2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m / 96; j++) {
			if (j % 2)
				for (int a = 0; a < blok; a++) // For even Values- Green
					wf << (char)255 << (char)0 << (char)0;
					// wf.write((char*)&d1, 1);
					// wf.write((char*)&d2, 1);
					// wf.write((char*)&d2, 1);
			else for (int a = 0; a < blok; a++) // For odd Values- Blue
				wf << (char)0 << (char)255 << (char)0;
				// wf.write((char*)&d2, 1);
				// wf.write((char*)&d1, 1);
				// wf.write((char*)&d2, 1);
		}
	}
	cout << "Done" << endl;
	system("pause");
	return 0;
}
