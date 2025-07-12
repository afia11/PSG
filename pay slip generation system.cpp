#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    double basicSalary;
    double overtimeHours;
};

class PayrollSystem {
private:
    vector<Employee> employees;
    double DA_rate = 0.1;
    double HRA_rate = 0.15;
    double medical_allowance_rate = 0.05;
    double professional_tax = 200;
    double overtime_rate = 50;

    Employee* findEmployee(int id) {
        for (auto &e : employees) {
            if (e.id == id)
                return &e;
        }
        return nullptr;
    }

public:
    void addEmployee() {
        Employee e;
        cout << "Enter Employee ID: ";
        cin >> e.id;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, e.name);
        cout << "Enter Basic Salary: ";
        cin >> e.basicSalary;
        cout << "Enter Overtime Hours: ";
        cin >> e.overtimeHours;
        employees.push_back(e);
        cout << "Employee added successfully.\n";
    }

    void setDA_rate() {
        cout << "Enter Dearness Allowance Rate (in decimal, e.g. 0.1 for 10%): ";
        cin >> DA_rate;
        cout << "DA rate updated.\n";
    }

    void setHRA_rate() {
        cout << "Enter HRA Rate (in decimal): ";
        cin >> HRA_rate;
        cout << "HRA rate updated.\n";
    }

    void setMedicalAllowance_rate() {
        cout << "Enter Medical Allowance Rate (in decimal): ";
        cin >> medical_allowance_rate;
        cout << "Medical Allowance rate updated.\n";
    }

    void setProfessionalTax() {
        cout << "Enter Professional Tax (fixed amount): ";
        cin >> professional_tax;
        cout << "Professional tax updated.\n";
    }

    void displayEmployeeDetails() {
        if (employees.empty()) {
            cout << "No employees to display.\n";
            return;
        }
        for (const auto &e : employees) {
            cout << "ID: " << e.id << ", Name: " << e.name << ", Basic Salary: " << e.basicSalary
                 << ", Overtime Hours: " << e.overtimeHours << endl;
        }
    }

    void computeOvertimeDues() {
        int id;
        cout << "Enter Employee ID to compute overtime dues: ";
        cin >> id;
        Employee* e = findEmployee(id);
        if (e == nullptr) {
            cout << "Employee not found.\n";
            return;
        }
        double overtimePay = e->overtimeHours * overtime_rate;
        cout << "Overtime dues for " << e->name << ": " << overtimePay << "\n";
    }

    void generatePaySlip() {
        int id;
        cout << "Enter Employee ID to generate pay slip: ";
        cin >> id;
        Employee* e = findEmployee(id);
        if (e == nullptr) {
            cout << "Employee not found.\n";
            return;
        }

        double da = e->basicSalary * DA_rate;
        double hra = e->basicSalary * HRA_rate;
        double medical = e->basicSalary * medical_allowance_rate;
        double overtimePay = e->overtimeHours * overtime_rate;

        double grossSalary = e->basicSalary + da + hra + medical + overtimePay;
        double netSalary = grossSalary - professional_tax;

        cout << "\n--- Pay Slip ---\n";
        cout << "Employee ID: " << e->id << "\n";
        cout << "Name: " << e->name << "\n";
        cout << "Basic Salary: " << e->basicSalary << "\n";
        cout << "Dearness Allowance (DA): " << da << "\n";
        cout << "House Rent Allowance (HRA): " << hra << "\n";
        cout << "Medical Allowance: " << medical << "\n";
        cout << "Overtime Pay: " << overtimePay << "\n";
        cout << "Professional Tax: " << professional_tax << "\n";
        cout << "Net Salary: " << netSalary << "\n";
        cout << "-----------------\n\n";
    }
};

int main() {
    PayrollSystem ps;
    int choice;

    do {
        cout << "\n--- Payroll System Menu ---\n";
        cout << "1. Add New Employee\n";
        cout << "2. Generate Pay Slip\n";
        cout << "3. Set Dearness Allowance Rate\n";
        cout << "4. Set HRA Rate\n";
        cout << "5. Set Professional Tax\n";
        cout << "6. Set Medical Allowance Rate\n";
        cout << "7. Display Employee Details\n";
        cout << "8. Compute Overtime Dues\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: ps.addEmployee(); break;
            case 2: ps.generatePaySlip(); break;
            case 3: ps.setDA_rate(); break;
            case 4: ps.setHRA_rate(); break;
            case 5: ps.setProfessionalTax(); break;
            case 6: ps.setMedicalAllowance_rate(); break;
            case 7: ps.displayEmployeeDetails(); break;
            case 8: ps.computeOvertimeDues(); break;
            case 9: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 9);

    return 0;
}
