#include <iostream>
#include <fstream>
using namespace std;

int writeFile(string&);
int readFile(string&);

int writeFile(string& filename){
    int N;
    int employeeid;
    string department;
    string employeename;
    int salary;
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
    return N;
}

int readFile(string& filename){
    ifstream ifs;
    int N;
    string employeename, department;
    int employeeid;
    int salary;
    double salaryavg, salarysum;

    ifs.open("employee.txt");
    if (!ifs)
    {
        cout << "File Open Error\n";
        exit(0);
    }

    if (ifs >> N){
        cout << N << "total employees" << endl;
    } else {
        cout << "Could not get number of employees" << endl;
        exit(0);
    }

    cout << "ID\t" << "NAME\t" << "DEPARTMENT\t" << "SALARY\n";

    for (int i = 0; i < N; i++){
        if (ifs >> employeeid >> employeename >> department >> salary){
            cout << employeeid << "\t" << employeename << "\t" << department << "\t" << salary << endl;
            salarysum += salary;
            salaryavg = salarysum / N;
            
        }
    }
    cout << "Sum of salaries: " << salarysum << "\tAverage salary: " << salaryavg;
    return N;
}
