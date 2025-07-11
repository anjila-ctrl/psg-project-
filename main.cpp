#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;
const int OT_RATE = 400;

int daRate = 50, hraRate = 20;
int profTax = 200, medAllowance = 1500;

struct Employee {
    int empNo;
    string name, address, designation, department;
    bool isPermanent;
    int basicSalary;
    int incomeTax;
    int overtimeHours;
};


Employee emps[MAX] = {
    {1, "Rajiv Karmakar", "Delhi", "Writer", "Content", true, 35000, 2000, 2},
    {2, "Reema Lagoo", "Mumbai", "Editor", "Publishing", true, 40000, 2500, 3},
    {3, "Anil Gomes", "Pune", "Designer", "Graphics", false, 30000, 2000, 4},
    {4, "Sanjiv Bansal", "Chennai", "Manager", "Sales", true, 45000, 3000, 5},
    {5, "Vaibhav Goenka", "Kolkata", "HR", "HR", true, 38000, 2500, 6},
    {6, "Gayatri Rao", "Delhi", "Developer", "IT", true, 42000, 2600, 5},
    {7, "Harish Dalmiya", "Bangalore", "Support", "Customer Service", false, 37000, 2200, 4}
};

int empCount = 7;


void setProfessionalTax() {
    cout << "Enter new Professional Tax amount: ";
    cin >> profTax;
    cout << "Professional Tax updated.\n";
}


void setMedicalAllowance() {
    cout << "Enter new Medical Allowance amount: ";
    cin >> medAllowance;
    cout << "Medical Allowance updated.\n";
}


void displayEmployeeDetails() {
    int empNo;
    cout << "Enter Employee number: ";
    cin >> empNo;

    if (empNo < 1 || empNo > empCount) {
        cout << "Invalid employee number!\n";
        return;
    }

    Employee emp = emps[empNo - 1];
    int da = emp.basicSalary * daRate / 100;
    int hra = emp.basicSalary * hraRate / 100;
    int pf = emp.isPermanent ? (emp.basicSalary * 12 / 100) : 0;
    int gross = emp.basicSalary + da + hra + medAllowance;
    int net = gross - pf - profTax - emp.incomeTax;

    cout << "\n--- Pay Slip ---\n";
    cout << "Emp No: " << emp.empNo << "\n";
    cout << "Name: " << emp.name << "\n";
    cout << "Address: " << emp.address << "\n";
    cout << "Designation: " << emp.designation << "\n";
    cout << "Department: " << emp.department << "\n";
    cout << "Employee Type: " << (emp.isPermanent ? "Permanent" : "Contractual") << "\n";
    cout << "Basic Salary: " << emp.basicSalary << "\n";
    cout << "DA: " << da << "\n";
    cout << "HRA: " << hra << "\n";
    cout << "Medical Allowance: " << medAllowance << "\n";
    if (emp.isPermanent) cout << "PF: " << pf << "\n";
    cout << "Professional Tax: " << profTax << "\n";
    cout << "Income Tax: " << emp.incomeTax << "\n";
    cout << "Gross Salary: " << gross << "\n";
    cout << "Net Salary  : " << net << "\n";
    cout << "-------------------\n";
}

void showOvertimeDues() {
    cout << "\nThe Overtime Dues for the employees are as follows:\n";
    cout << "Emp No\tEmp. Name\t\tOvertime Dues\n";
    for (int i = 0; i < empCount; ++i) {
        cout << emps[i].empNo << "\t" << setw(18) << left << emps[i].name
             << "\t" << emps[i].overtimeHours * OT_RATE << "\n";
    }
}

void showAllEmployees() {
    cout << "\nAll Employee Summary:\n";
    cout << "Emp No\tName\t\t\tType\t\tBasic Salary\n";
    for (int i = 0; i < empCount; ++i) {
        cout << emps[i].empNo << "\t"
             << setw(20) << left << emps[i].name << "\t"
             << (emps[i].isPermanent ? "Permanent" : "Contractual") << "\t"
             << emps[i].basicSalary << "\n";
    }
}

void calculateGrossNetOnly() {
    int empNo;
    cout << "Enter Employee number: ";
    cin >> empNo;

    if (empNo < 1 || empNo > empCount) {
        cout << "Invalid employee number!\n";
        return;
    }

    Employee emp = emps[empNo - 1];
    int da = emp.basicSalary * daRate / 100;
    int hra = emp.basicSalary * hraRate / 100;
    int pf = emp.isPermanent ? (emp.basicSalary * 12 / 100) : 0;
    int gross = emp.basicSalary + da + hra + medAllowance;
    int net = gross - pf - profTax - emp.incomeTax;

    cout << "Gross Salary: " << gross << "\n";
    cout << "Net Salary  : " << net << "\n";
}


int main() {
    int choice;
    do {
        cout << "\n--- PAY SLIP GENERATION SYSTEM ---\n";
        cout << "5. Set Professional Tax\n";
        cout << "6. Set Medical Allowance\n";
        cout << "7. Display Employee Details\n";
        cout << "8. Show Overtime Dues\n";
        cout << "9. Show All Employees (Extra)\n";
        cout << "10. Gross & Net Only (Extra)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 5: setProfessionalTax(); break;
            case 6: setMedicalAllowance(); break;
            case 7: displayEmployeeDetails(); break;
            case 8: showOvertimeDues(); break;
            case 9: showAllEmployees(); break;
            case 10: calculateGrossNetOnly(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n"; break;
        }
    } while (choice != 0);

    return 0;
}
