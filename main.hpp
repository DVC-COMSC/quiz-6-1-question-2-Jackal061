#include <iostream>
#include <fstream>
using namespace std;

void writeFile(string&);

void writeFile(string& filename){
    int N;
    int employeeid;
    string department;
    string employeename;
    int salary;
    int N;
    ofstream ofs;


    ofs.open("employee.txt");
    if (!ofs)
    {
        cout << "File Open Error\n";
        exit(0);
    }

    cout << "amount of employees: ";
    cin >> N;
    ofs << N << endl;

    for (int i = 0; i < N; i++){
        cout << "Enter the id, name, department, and salary of the employee: " << endl;
        cin >> employeeid >> employeename >> department >> salary;
        ofs << employeeid << "\t" << employeename << "\t" << department << "\t" << salary << endl;
    }

    ofs.close();
}
