#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// Function to format numbers with commas and 2 decimal places
string formatWithCommas(double value) {
    stringstream ss;
    ss << fixed << setprecision(2) << value;

    string num = ss.str();
    int insertPos = num.find('.') - 3;

    while (insertPos > 0) {
        num.insert(insertPos, ",");
        insertPos -= 3;
    }
    return num;
}

int main() {
    string empId, empName, jobDesc, payrollDate;
    double hoursWorked, ratePerHour;
    double grossPay, taxRate, taxAmount, netPay;

    // Input section
    cout << "Enter Employee ID     : ";
    getline(cin, empId);

    cout << "Enter Employee Name   : ";
    getline(cin, empName);

    cout << "Enter Job Description : ";
    getline(cin, jobDesc);

    cout << "Enter Payroll Date    : ";
    getline(cin, payrollDate);

    cout << "Enter Hours Worked    : ";
    cin >> hoursWorked;

    cout << "Enter Rate per Hour   : ";
    cin >> ratePerHour;

    // Gross pay computation
    if (hoursWorked > 40) {
        grossPay = (ratePerHour * 40) +
                   (1.5 * ratePerHour * (hoursWorked - 40));
    } else {
        grossPay = ratePerHour * hoursWorked;
    }

    // Tax computation
    if (grossPay > 25000) {
        taxRate = 0.12;
    } else if (grossPay >= 15000) {
        taxRate = 0.10;
    } else {
        taxRate = 0.08;
    }

    taxAmount = grossPay * taxRate;
    netPay = grossPay - taxAmount;

    // Output section
    cout << "\n========== PAYROLL DETAILS ==========\n";
    cout << "Employee ID      : " << empId << '\n';
    cout << "Employee Name    : " << empName << '\n';
    cout << "Job Description  : " << jobDesc << '\n';
    cout << "Payroll Date     : " << payrollDate << '\n';
    cout << "-------------------------------------\n";
    cout << "Gross Pay        : PHP " << formatWithCommas(grossPay) << '\n';
    cout << "Tax Rate         : " << fixed << setprecision(2)
        << taxRate * 100 << "%\n";
    cout << "Deductions       : PHP " << formatWithCommas(taxAmount) << '\n';
    cout << "Net Pay          : PHP " << formatWithCommas(netPay) << '\n';
    cout << "=====================================\n";
    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
