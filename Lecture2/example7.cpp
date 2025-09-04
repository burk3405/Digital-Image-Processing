#include<iostream>
#include<fstream>
#include <string>
using namespace std;

struct Student{ 
    int roll_no; 
    string fname; 
    string last; 
};

int main() {
    ofstream wf("student.dat", ios::out | ios::binary);
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return 1;
    }
    
    Student wstu[3];
    wstu[0].roll_no = 1;
    wstu[0].fname = "Ram";
    wstu[0].last = "Krish";
    wstu[1].roll_no = 2;
    wstu[1].fname = "Shyam";
    wstu[1].last = "Kiyak";
    wstu[2].roll_no = 3;
    wstu[2].fname = "Madhu";
    wstu[2].last = "Rahim";
    
    // Write each structure to file.
    
    for (int i = 0; i < 3; i++)
        wf.write((char *)&wstu[i], sizeof(Student));
    wf.close();

    //Open the file in binary mode for reading
    ifstream rf("student.dat", ios::in | ios::binary);
    
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    //Declare a new structure and read each structure.

    Student rstu[3];
    for (int i = 0; i < 3; i++)
        rf.read((char *)&rstu[i], sizeof(Student));
    rf.close();
    
    //Display the read structured data
    cout << "Student's Details:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Roll No: " << wstu[i].roll_no << endl;
        cout << "Name: " << wstu[i].fname << endl;
        cout << "Last Name: " << wstu[i].last << endl;
        cout << endl;
        }
return 0;
}
