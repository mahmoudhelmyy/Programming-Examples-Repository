/*
 * Calculator Program
 * Author: Mahmoud Helmy
 * Class: 3
 * Instructor: Eng. Ahmed Saad
 * Description: This program provides a menu-based calculator for performing various arithmetic operations.
 */

#include <stdio.h>
#include <stdlib.h>

/* Constants for operation choices */
#define ADD   1
#define SUB   2
#define MUL   3
#define DIV   4
#define POW   5
#define FACT  6
#define EXIT  7

/* Function prototypes */
double add(double x, double y);
double subtract(double x, double y);
double multiplication(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double factorial(double num1);

int main(void) {
    double number1, number2;
    double result = 0;
    int choice;

    /* Array of function pointers for different operations */
    double (*functionPtr[5])(double, double);
    double (*FactorialPtr)(double);
    functionPtr[0] = &add;
    functionPtr[1] = &subtract;
    functionPtr[2] = &multiplication;
    functionPtr[3] = &divide;
    functionPtr[4] = &power;
    FactorialPtr = &factorial;

    /* Main loop for calculator */
    while (1) {
        printf("Calculator Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Factorial\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        /* Based on user's choice, perform the selected operation */
        switch (choice) {
            case ADD:
                printf("Enter first number: ");
                scanf("%lf", &number1);
                printf("Enter second number: ");
                scanf("%lf", &number2);
                result = (*functionPtr[0])(number1, number2);
                break;
            case SUB:
                printf("Enter first number: ");
                scanf("%lf", &number1);
                printf("Enter second number: ");
                scanf("%lf", &number2);
                result = (*functionPtr[1])(number1, number2);
                break;
            case MUL:
                printf("Enter first number: ");
                scanf("%lf", &number1);
                printf("Enter second number: ");
                scanf("%lf", &number2);
                result = (*functionPtr[2])(number1, number2);
                break;
            case DIV:
                printf("Enter first number: ");
                scanf("%lf", &number1);
                printf("Enter second number: ");
                scanf("%lf", &number2);
                result = (*functionPtr[3])(number1, number2);
                break;
            case POW:
                printf("Enter base number: ");
                scanf("%lf", &number1);
                printf("Enter exponent: ");
                scanf("%lf", &number2);
                result = (*functionPtr[4])(number1, number2);
                break;
            case FACT:
                printf("Enter a non-negative integer: ");
                scanf("%lf", &number1);
                result = (*FactorialPtr)(number1);
                break;
            case EXIT: // Exit the program gracefully
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid operation.\n");
        }

        printf("Result = %lf\n", result);
    }
    return 0;
}

/* Function to perform addition */
double add(double x, double y) {
    return (x + y);
}

/* Function to perform subtraction */
double subtract(double x, double y) {
    return (x - y);
}

/* Function to perform multiplication */
double multiplication(double x, double y) {
    return x * y;
}

/* Function to perform division */
double divide(double x, double y) {
    if (y == 0) {
        printf("Undefined (Divide by zero)\n");
        exit(1);
    }
    return x / y;
}

/* Function to calculate power */
double power(double x, double y) {
    int i;
    double result = 1;
    if (y > 0) {
        for (i = 0; i < y; ++i) {
            result *= x;
        }
    } else if (y < 0) {
        y = -y;
        for (i = 0; i < y; ++i) {
            result *= x;
        }
        result = 1 / result;
    }
    return result;
}

/* Function to calculate factorial */
double factorial(double num1) {
    int i;
    double result = 1;
    if (num1 < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        exit(1);
    } else {
        for (i = 1; i <= num1; ++i) {
            result *= i;
        }
    }
    return result;
}
