#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAX = 10000;
string names[MAX];
int ages[MAX];
double salaries[MAX];
char genders[MAX];
int added = 0; //  number of emloyees


int menu() {
    // This function provides to see a process which we will use. 

    int choice = -1;
    while(choice == -1) {
        cout << "1) Add a new employee" << endl;
        cout << "2) Print all employees" << endl;
        cout << "3) Delete by age" << endl;
        cout << "4) Update Salary by name" << endl;
        cout << "5) Exit" << endl;
        cin >> choice;
        if (choice == 5)
            abort();
        
        if (!(1 <= choice && choice <=5)) {
            cout << "Invalid choice. Please try again!" << endl;
            choice = -1;
        }
    }
    return choice;
}

void addEmployee() {
    // This function provides to add new users. 
    cout << "Enter a name:";
    cin >> names[added];
    cout << endl;

    cout << "Enter an age:";
    cin >> ages[added];
    cout << endl;

    cout << "Enter salary:";
    cin >> salaries[added];
    cout << endl;

    cout << "Enter a gender (M/F):";
    cin >> genders[added];
    cout << endl;
    
    added++;
}

void printEmployees() {
    // This function provides to see all users. 

    for (int i = 0; i < added; i++) {
        if (ages[i] != -1) {
            cout << names[i] <<" "<< ages[i] <<" "<< salaries[i] <<" "<< genders[i] << endl;
        }
    }
}

void deleteByAge() {
    /* 
        This function provides to delete the user by age.
        we enter the starting age and the ending age to delete an user.
    */
    int start, end;
    cout << "Enter start and end age: " << endl;
    cin >> start >> end;
    
    for (int i = 0; i < added; i++) {
        if (start <= ages[i] && ages[i] <= end)
            ages[i] = -1;
    }
}

void updateSalary() {
    // This function provides to update the user salary. 

    string name; 
    int salary;
    cout << "Enter the name and salary: ";
    cin >> name >> salary;
    cout << endl;

    bool found = false;
    for (int i = 0; i < added; i++) {
        if (ages[i] != -1 && names[i] == name) {
            found = true;
            salaries[i] = salary;
            break;
        }
    }
    if (!found)
        cout << "No employee with this name" << endl; 
}

void employeeSystem() {
    // This function provides to select a process which we will use. 

    while (true) {
        switch(menu()) {
            case 1:
                addEmployee();
                break;
            case 2:
                printEmployees();
                break;
            case 3:
                deleteByAge();
                break;
            case 4:
                updateSalary();
                break;
            default:
                cout << "Invalid Value. Try Again!" << endl;
        }
    }
}

int main() {
  employeeSystem();
  return 0;
}