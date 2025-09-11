// Duplicating a PBM image (Gray Scale)
// Note that this example assumes a PBM file with a header
// P4 width height #of_colors like
// P4 512 768 255
// Data comes after the first line
// If not modify it using an editor such as Notepad+
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream input_1;
	ofstream output_1;
	string header;

	if (argc > 2) {
		// file name
		input_1.open(argv[1], ios::in | ios::binary);
		output_1.open(argv[2], ios::out | ios::binary);
	}
	else {
		fprintf(stderr, "argv[1] for reading and argv[2] for writing");
		exit(0);
	}
	getline(input_1, header);

	//header w,h extract

	string s_w, s_h;
	s_w = header.substr(3, 3);
	s_h = header.substr(7, 3);
	int w = stoi(s_w), h = stoi(s_h);
	cout << header << " h= " << h << " w= " << w << endl;
	//matrix for first channel
	char** in_matrix_ch1 = new char* [h];
	for (int i = 0; i < h; ++i)
		in_matrix_ch1[i] = new char[w];
	//matrix for second channel
	char** in_matrix_ch2 = new char* [h];
	for (int i = 0; i < h; ++i)
		in_matrix_ch2[i] = new char[w];
	//matrix for third channel
	char** in_matrix_ch3 = new char* [h];
	for (int i = 0; i < h; ++i)
		in_matrix_ch3[i] = new char[w];

	unsigned char r, g, b;
	//reading
	for (int i_h = 0; i_h < h; i_h++) {
		for (int i_w = 0; i_w < w; i_w++) {
			
			input_1.read((char*)&r, 1);
			input_1.read((char*)&g, 1);
			input_1.read((char*)&b, 1);
			in_matrix_ch1[i_h][i_w] = r;
			in_matrix_ch2[i_h][i_w] = g;
			in_matrix_ch3[i_h][i_w] = b;
		}
	}
	// Header does not have a return char. Add it/
	header = header + '\n';
	// Convert header to C language string type, and write it
	output_1.write(header.c_str(), header.length());
	// Write the data.
	for (int i_h = 0; i_h < h; i_h++) {
		for (int i_w = 0; i_w < w; i_w++) {
			output_1.write((char*)&in_matrix_ch1[i_h][i_w], 1);
			output_1.write((char*)&in_matrix_ch2[i_h][i_w], 1);
			output_1.write((char*)&in_matrix_ch3[i_h][i_w], 1);
		}
	}
	output_1.close();
	return 0;
}
