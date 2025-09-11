#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
#define BF_TYPE 0x4D42
class bitmap
{
private:
//bmpHeader
unsigned short int type;
unsigned int sizeFile;
unsigned short int reserved1, reserved2;
unsigned int offset;
//bmpInfoHeader
unsigned int sizeInfoHeader;
int width, height;
unsigned short int planes;
unsigned short int bits;
unsigned int compression;
unsigned int imagesize;
int xresolution, yresolution;
unsigned int ncolors;
unsigned int importantcolors;
//pointers for 2-D r, g, b arrays
unsigned char **r, **g, **b;
public:
bitmap(fstream&);
~bitmap();
bool readHeader(fstream&);
bool writeHeader(fstream&);
bool readInfoHeader(fstream&);
bool writeInfoHeader(fstream&);
void print();
void gray();
void readBitmap(fstream&);
void writeBitmap(fstream&);
};
bitmap::bitmap(fstream &input)
{
if(readHeader(input)!=true)
{
cout<<"Error reading file header"<<endl;
exit(1);
}
if(readInfoHeader(input)!=true)
{
cout<<"Error reading file information header"<<endl;
exit(1);
}
if(type!=BF_TYPE)
{
cout<<"This is not a bitmap image"<<endl;
exit(1);
}
r=new unsigned char *[width];
g=new unsigned char *[width];
b=new unsigned char *[width];
for(int i=0; i<width; i++)
{
r[i]=new unsigned char [height];
g[i]=new unsigned char [height];
b[i]=new unsigned char [height];
}
}
bitmap::~bitmap()
{
for(int i=0; i<width; i++)
{
delete [] r[i];
delete [] g[i];
delete [] b[i];
}
delete [] r;
delete [] g;
delete [] b;
}
bool bitmap::readHeader(fstream &input)
{
input.read((char*)&type, 2);
input.read((char*)&sizeFile, 4);
input.read((char*)&reserved1, 2);
input.read((char*)&reserved2, 2);
input.read((char*)&offset, 4);
return true;
}
bool bitmap::writeHeader(fstream &output)
{
output.write((char*)&type, 2);
output.write((char*)&sizeFile, 4);
output.write((char*)&reserved1, 2);
output.write((char*)&reserved2, 2);
output.write((char*)&offset, 4);
return true;
}
bool bitmap::readInfoHeader(fstream &input)
{
input.read((char*)&sizeInfoHeader, 4);
input.read((char*)&width, 4);
input.read((char*)&height, 4);
input.read((char*)&planes, 2);
input.read((char*)&bits, 2);
input.read((char*)&compression, 4);
input.read((char*)&imagesize, 4);
input.read((char*)&xresolution, 4);
input.read((char*)&yresolution, 4);
input.read((char*)&ncolors, 4);
input.read((char*)&importantcolors, 4);
return true;
}
bool bitmap::writeInfoHeader(fstream &output)
{
output.write((char*)&sizeInfoHeader, 4);
output.write((char*)&width, 4);
output.write((char*)&height, 4);
output.write((char*)&planes, 2);
output.write((char*)&bits, 2);
output.write((char*)&compression, 4);
output.write((char*)&imagesize, 4);
output.write((char*)&xresolution, 4);
output.write((char*)&yresolution, 4);
output.write((char*)&ncolors, 4);
output.write((char*)&importantcolors, 4);
return true;
}
void bitmap::print()
{
cout<<"===Information retrieved from image headers==="<<endl
<<"Image data size: "<<sizeFile<<" KB"<<endl
<<"Info header size: "<<sizeInfoHeader<<" KB"<<endl
<<"Image Width: "<<width<<" pixels"<<endl
<<"Image height: "<<height<<" pixels"<<endl
<<"Bitcount: "<<bits<<" bits"<<endl;
}
void bitmap::gray()
{
unsigned short average;
for(int i=0; i<width; i++)
for(int j=0; j<height; j++)
{
average=(r[i][j]+g[i][j]+b[i][j])/3;
r[i][j]=average;
g[i][j]=average;
b[i][j]=average;
}
}
void bitmap::readBitmap(fstream& input)
{
for(int i=0; i<width; i++)
for(int j=0; j<height; j++)
{
input.read((char*)&r[i][j], 1);
input.read((char*)&g[i][j], 1);
input.read((char*)&b[i][j], 1);
}
}
void bitmap::writeBitmap(fstream& output)
{
for(int i=0; i<width; i++)
for(int j=0; j<height; j++)
{
output.write((char*)&r[i][j], 1);
output.write((char*)&g[i][j], 1);
output.write((char*)&b[i][j], 1);
}
}
