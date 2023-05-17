
#include <iostream>
using namespace std;

struct student
{
    char name[10];
    int rollno;
    float CGPI;
    int Semester;
};

int main()
{
    int l;

    // printf("Enter no of students : ");
    cout << "Enter no of students :" << endl;
    cin >> l;
    struct student *info = (struct student *)malloc(l * sizeof(struct student));

    // Taking INPUT of Information:
    for (int i = 0; i < l; i++)
    {
        cout << "Enter the info of the New Student as format Name Roll NO,  CGPI  Semester"
             << "for the " << i + 1 << "th Student" << endl;

        cin >> info[i].name >> info[i].rollno >> info[i].CGPI >> info[i].Semester;
    }

    // Printing the info of students with CGPI over k
    int k;
    cout << "Enter the value of K" << endl;
    cin >> k;

    cout << "Student with CGPI greater than" << k << endl;
    for (int i = 0; i < l; i++)
    {

        if (info[i].CGPI >= k)
        {
            cout << i + 1 << " " << info[i].name << " " << info[i].rollno << " " << info[i].CGPI << " " << info[i].Semester << endl;
        }
    }

    // Insert at Kth Position after Taking Input From User

    info = (struct student *)realloc(info, (l + 1) * sizeof(struct student));
    l++;

    int K_insert;
    cout << "Enter the Position where insertion needs to be made" << endl;

    cin >> K_insert;

    for (int i = l - 1; i >= K_insert - 1; i--)
    {
        info[i + 1] = info[i];
    }
    // Take in Details of New Student
    cout << "Enter the info of the New Student as Name Roll NO,  CGPI  Semester" << endl;

    cin >> info[K_insert - 1].name >> info[K_insert - 1].rollno >> info[K_insert - 1].CGPI >> info[K_insert - 1].Semester;

    // Print the Updated Record

    for (int i = 0; i < l; i++)
    {
        cout << i + 1 << " " << info[i].name << " " << info[i].rollno << " " << info[i].CGPI << " " << info[i].Semester << endl;
    }

    return 0;
}