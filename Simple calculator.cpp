#include <iostream>
using namespace std;

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2, result;
    char operation;
    bool validOperation = true;

    // Display menu to the user
    cout << "Simple Calculator\n";
    cout << "=================\n";
    cout << "Enter two numbers and choose an operation:\n";

    // Input two numbers
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Input the operation
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the chosen operation
    switch (operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            if (num2 != 0) {
                result = divide(num1, num2);
            } else {
                cout << "Error: Division by zero is not allowed.\n";
                validOperation = false;
            }
            break;
        default:
            cout << "Error: Invalid operation.\n";
            validOperation = false;
    }

    // Display the result if the operation is valid
    if (validOperation) {
        cout << "Result: " << result << endl;
    }

    return 0;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

