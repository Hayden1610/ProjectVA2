#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define PRE_RELEASE

struct STUDENT_DATA // struct for student data
{
    string Firstname;
    string Lastname;
    string Email; 
};

int main()
{
    vector<STUDENT_DATA> student; // creating vector space

#ifdef PRE_RELEASE
    cout << "Running in Pre-release mode" << endl;
    ifstream studentinfo("StudentData_Emails.txt"); 
#else
    cout << "Running in Debug mode" << endl;
    ifstream studentinfo("StudentData.txt"); 
#endif

    if (!studentinfo.is_open())
    {
        cout << "Error Opening File" << endl;
        return 1;
    }

    string stline;
    while (getline(studentinfo, stline))
    {
        stringstream ss(stline);
        string firstName, lastName, email;
        getline(ss, firstName, ',');
        getline(ss, lastName, ','); 
#ifdef PRE_RELEASE
        getline(ss, email); 
#endif
        STUDENT_DATA tempstudentdata;
        tempstudentdata.Firstname = firstName;
        tempstudentdata.Lastname = lastName;
#ifdef PRE_RELEASE
        tempstudentdata.Email = email; 
#endif
        student.push_back(tempstudentdata);
    }
    studentinfo.close();

#ifdef _DEBUG
    for (int i = 0; i < student.size(); i++)
    {
        cout << "Student Name: " << student[i].Firstname << " " << student[i].Lastname;
#ifdef PRE_RELEASE
        cout << ", Email: " << student[i].Email;
#endif
        cout << endl;
    }
#endif 

    return 0;
}
