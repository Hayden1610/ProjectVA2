#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

struct STUDENT_DATA //struct for student data
{
    string Firstname;
    string Lastname;
};

int main()
{
    ifstream myfile("StudentData.txt"); //opening file for student data
    if (!myfile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    vector<STUDENT_DATA> student; //creating vector space

    string line; //parsing the data
    while (getline(myfile, line)) {
        stringstream ss(line);
        string firstName, lastName;
        if (getline(ss, firstName, ',') && getline(ss, lastName)) {
            STUDENT_DATA tempstudentdata;
            tempstudentdata.Firstname = firstName;
            tempstudentdata.Lastname = lastName;
            student.push_back(tempstudentdata); //pushing the data into the vector space
        }
    }
    myfile.close();

    return 0;
}
