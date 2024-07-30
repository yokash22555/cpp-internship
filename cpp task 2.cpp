 Task 2: simple calculator
#include <iostream>

int main() {
    char operation;
    double num1, num2, result;

    // Display menu
    std::cout << "Simple Calculator" << std::endl;
    std::cout << "Select operation:" << std::endl;
    std::cout << " + : Addition" << std::endl;
    std::cout << " - : Subtraction" << std::endl;
    std::cout << " * : Multiplication" << std::endl;
    std::cout << " / : Division" << std::endl;

    // Read user choice
    std::cout << "Enter operation: ";
    std::cin >> operation;

    // Read numbers
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Perform calculation based on the operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
            } else {
                std::cout << "Error: Division by zero!" << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation!" << std::endl;
            break;
    }

    return 0;
}
