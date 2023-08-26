/* =======================================================================================
 *									Calculator Program
 * =======================================================================================
 * Author: Mahmoud Helmy
 * Description: This program performs various arithmetic operations such as addition, subtraction,
 * multiplication, division, exponentiation, and factorial. It takes user inputs for the operation
 * and two numbers, and then calculates and displays the result.
 */



#include <stdio.h>
#include <stdlib.h>

/* Function to perform calculator operations
 * @param num1 First number
 * @param num2 Second number
 * @param operation Operation code (1: +, 2: -, 3: *, 4: /, 5: ^, 6: !)
 * @return Result of the operation
 */
double calculator(double num1, double num2, int operation) {
    double result = 0;
    int i;
    double power = 1;
    double factorial = 1;

    switch (operation) {
    case 1:
        result = num1 + num2;  // Addition
        break;
    case 2:
        result = num1 - num2;  // Subtraction
        break;
    case 3:
        result = num1 * num2;  // Multiplication
        break;
    case 4:
        // Division
        printf("NOTE: first number divided by second number!\n");
        if (num2 == 0) {
            printf("Undefined (Divide by zero)\n");
            exit(1);
        } else {
            result = num1 / num2;
        }
        break;
    case 5:
        // Exponentiation
        printf("NOTE: first number power second number! (e.g 2^2 = 4)\n");
        if (num2 > 0) {
            for (i = 0; i < num2; ++i) {
                power = num1 * power;
            }
        } else if (num2 < 0) {
            num2 = -num2;
            for (i = 0; i < num2; ++i) {
                power = num1 * power;
            }
            power = 1 / power;
        } else {
            power = 1;
        }
        result = power;
        break;
    case 6:
        // Factorial
        printf("NOTE: Factorial of the first number!\n");
        if (num1 < 0) {
            printf("Factorial is not defined for negative numbers.\n");
            exit(1);
        } else {
            for (i = 1; i <= num1; ++i) {
                factorial *= i;
            }
            result = factorial;
        }
        break;
    default:
        printf("Please Enter Invalid Operation!!\n");
    }

    return result;
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int op;
    double number1, number2, result;

    while (1) {
        // Input the operation
        printf("Enter operation (1: +, 2: -, 3: *, 4: /, 5: ^, 6: !): \n");
        scanf("%d", &op);

        // Input the first number
        printf("Enter first number: \n");
        scanf("%lf", &number1);

        // Check for factorial operation
        if (op == 6) {
            result = calculator(number1, 0, op); // Pass 0 as second number for factorial
        } else {
            // Input the second number
            printf("Enter second number: \n");
            scanf("%lf", &number2);
            result = calculator(number1, number2, op);
        }

        printf("result = %lf\n", result);
    }

    return 0;
}
