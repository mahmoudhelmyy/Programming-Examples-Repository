# Programming Examples Repository

Welcome to the Programming Examples Repository! This repository showcases a collection of simple yet illustrative programming examples across various topics. Each program is designed to demonstrate fundamental concepts and techniques, making it a valuable resource for learning and practicing programming skills.

## Table of Contents

- **[Bus Reservation System]**: A command-line bus reservation system that allows users to book and manage bus trips.

- **[Calculator Program]**: A versatile calculator program that performs basic arithmetic operations, including addition, subtraction, multiplication, division, exponentiation, and factorial.

- **[Maximum Amount of Water Trapped]**: Calculates the maximum amount of water that can be trapped between different height bars.

- **[Array Rotation Functions]**: Demonstrates array rotation methods, both left and right, by a specified number of positions.

- **[Finding Second Biggest Number]**: Finds and displays the second biggest number in an array.

- **[Basic Stack Implementation]**: Implements a basic stack data structure along with common stack operations, adhering to coding standards.

- **[Stock Profit Calculation]**: Calculates the maximum profit from buying and selling stocks using single and multiple transactions.

- **[Swapping, Fibonacci, and Sorting]**: Illustrates swapping methods, Fibonacci sequence generation, and sorting function.

- **[Palindrome Checker]**: Checks if a number is a palindrome and provides its reversed form, following MISRA-C 2012 guidelines.

Feel free to explore, modify, and learn from these examples to enhance your programming skills. Happy coding!
## Author
- Mahmoud Helmy


# 1. Bus Reservation System

A simple command-line bus reservation system that allows users to book and manage bus trips.

## Features

- **User Authentication:** Log in with a username and password.
- **View Available Trips:** Display information about available bus trips.
- **Book a Trip:** Reserve seats for a specific trip.
- **Cancel a Trip:** Cancel a previously booked trip.
- **User-Friendly Interface:** Easy-to-use command-line interface.

## Getting Started

1. Clone the repository.
2. Compile the `BusReservationSystem.c` source file.
3. Run the compiled executable.
4. Follow the prompts to interact with the system.

## Usage

1. Log in with your username and password.
2. Choose from the following options:

   | Option | Action                |
   |--------|-----------------------|
   | 1      | View available trips  |
   | 2      | Book a trip           |
   | 3      | Cancel a trip         |
   | 4      | Log out               |

3. Log out when finished.
## Version
1.0

# 2. Calculator Program

A simple calculator program that performs various arithmetic operations such as addition, subtraction, multiplication, division, exponentiation, and factorial. The program takes user inputs for the operation and two numbers, calculates the result, and displays it.

## Features

- Arithmetic Operations: Addition, Subtraction, Multiplication, Division, Exponentiation, and Factorial.
- User-Friendly Interface: The program prompts the user for the operation and numbers.

## Getting Started

1. **Clone the Repository or Download the Source Code.**
2. **Compile and Run:**
   - Compile the `calculator.c` source file using a C compiler (e.g., gcc).
   - Run the compiled executable.
3. **Follow the Prompts:**
   - Choose an operation and enter numbers as prompted.

## Usage

1. **Choose an Operation:**

   | Operation | Description          |
   |-----------|----------------------|
   | 1         | Addition             |
   | 2         | Subtraction          |
   | 3         | Multiplication       |
   | 4         | Division             |
   | 5         | Exponentiation       |
   | 6         | Factorial            |

2. **Enter Numbers:**
   - For operations other than factorial, enter two numbers.
   - For factorial, enter only the first number.

3. **View Result:**
   - The program will display the calculated result.

## Note

- For division (4), avoid dividing by zero as it results in an undefined value.
- For exponentiation (5), enter the first number as the base and the second number as the exponent.
- For factorial (6), only the first number is considered. Factorial is not defined for negative numbers.
# 3. Maximum Amount of Trapped Water Calculator

A program that calculates the maximum amount of water that can be trapped between bars of different heights. This problem is often referred to as the "Container With Most Water" problem.

## Description

Given an array of bar heights, the program calculates the maximum amount of water that can be trapped between the bars when forming a container. The algorithm employs a two-pointer approach to find the container's maximum area efficiently.

## Features

- Efficient Algorithm: Utilizes a two-pointer approach to find the maximum trapped water area.
- MISRA-C 2012 Guidelines: The code is compliant with MISRA-C 2012 standards.
- User-Friendly Output: Displays the maximum trapped water amount.

## Getting Started

1. Clone the repository or download the source code.
2. Compile the `MaximumAmountOfWater.c` source file using a C compiler (e.g., gcc).
3. Run the compiled executable.
4. The program will display the maximum trapped water amount.

## Algorithm Explanation

The algorithm maintains two pointers, one at the beginning and another at the end of the array. It calculates the area between the two pointers, then moves the pointer pointing to the smaller bar towards the other pointer. This approach ensures that we explore the possibilities of larger areas with taller bars while maintaining a wide base.

## Example

Consider the following heights array: `[1, 8, 6, 2, 5, 4, 8, 3, 7]`
Running the program with this array will output: `Maximum trapped water: 49`

# 4. Array Rotation Functions

A program that demonstrates two methods for rotating an array left or right by a given number of positions.

## Description

This program provides functions to rotate an array in both left and right directions. The rotations are performed by moving elements within the array. The code ensures that the array is rotated by a specific number of positions without exceeding the array bounds.

## Features

- Array Rotation: Rotate an array left or right by a specified number of positions.
- User-Friendly Output: Display the original and rotated arrays.

## Getting Started

1. Clone the repository or download the source code.
2. Compile the `RotationFunction.c` source file using a C compiler (e.g., gcc).
3. Run the compiled executable.
4. Observe the original and rotated arrays in the program's output.

## Rotation Methods

1. **Left Rotation (`rotate_left` function):**
   - The left rotation moves the first `k` elements to the end of the array.
   - For example, if the array is [1, 2, 3, 4, 5] and `k` is 2, the rotated array becomes [3, 4, 5, 1, 2].

2. **Right Rotation (`rotate_right` function):**
   - The right rotation moves the last `k` elements to the beginning of the array.
   - For example, if the array is [1, 2, 3, 4, 5] and `k` is 2, the rotated array becomes [4, 5, 1, 2, 3].

## Example

Consider the array `[1, 2, 3, 4, 5]` and rotating it left by 2 positions:

```plaintext
Original array = 1 2 3 4 5
Rotated array = 3 4 5 1 2
```
# 5. Second Biggest Number Finder

A program that finds and displays the second biggest number in an array of integers.

## Description

This program provides a function to find the second biggest number in an array of integers. It sorts the array in descending order and then extracts the second element, which corresponds to the second biggest number.

## Features

- Second Biggest Number: Finds and displays the second biggest number in the array.
- Array Sorting: Sorts the array in descending order.
- User-Friendly Output: Displays the original array and the second biggest number.

## Getting Started

1. Clone the repository or download the source code.
2. Compile the `SecondBiggestNumber.c` source file using a C compiler (e.g., gcc).
3. Run the compiled executable.
4. Observe the original array and the second biggest number in the program's output.

## Algorithm Explanation

1. The program sorts the array in descending order using a simple bubble sort algorithm.
2. If the array size is at least 2, it prints the sorted array and extracts the second element as the second biggest number.

## Example

Consider the array `[13, 16, 14, 1]`:

```plaintext
Original array: 13 16 14 1
Sorted array: 16 14 13 1
Second biggest number is 14
```
# 6. Stack Implementation in C

A basic implementation of a stack data structure in C, along with push and pop operations.

## Description

This program provides a simple implementation of a stack data structure in C. It includes functions to create a stack, push elements onto the stack, pop elements from the stack, and print the elements that were popped.

## Features

- Stack Creation: Create a stack of a specified size.
- Push Operation: Push elements onto the stack.
- Pop Operation: Pop elements from the stack.
- Printing Popped Elements: Print the elements that were popped from the stack.
- Memory Management: Proper memory allocation and deallocation.

## Getting Started

1. Clone the repository or download the source code.
2. Compile the `Stack.c` source file using a C compiler (e.g., gcc).
3. Run the compiled executable.
4. Observe the behavior of the stack operations and output.

## Implementation Details

- A stack structure is defined with an array to hold elements, the maximum size of the stack, and the index of the top element.
- The `create_stack` function dynamically allocates memory for the stack structure and its array. It returns a pointer to the created stack.
- The `push` function adds an element to the stack if space is available.
- The `pop` function removes and returns the top element from the stack if it's not empty.
- The `print` function pops and prints all elements in the stack.

## Example

```plaintext
Stack FULL!!
3
2
1
Stack EMPTY!!
```

# 7. Stock Profit Calculator
Find the maximum profit from buying and selling stocks


## Description

This program calculates the maximum profit that can be achieved from buying and selling stocks using two different strategies: a single transaction and multiple transactions.

## Features

- Calculate Maximum Profit: Calculates the maximum profit using a single transaction or multiple transactions.
- Optimized Strategies: Utilizes efficient algorithms to determine the best buying and selling decisions.

## Getting Started

1. Clone the repository or download the source code.
2. Compile the `Stock.c` source file using a C compiler (e.g., gcc).
3. Run the compiled executable.
4. Observe the calculated maximum profit for the provided stock prices.

## Algorithms

- `maxProfit`: Calculates the maximum profit using a single transaction. It finds the best buying and selling points to maximize profit.
- `maxProfit2`: Calculates the maximum profit using multiple transactions. It identifies increasing price trends and accumulates profit.

## Example

For the stock prices: `[2, 6, 3, 10]`

- Using single transaction: Maximum Profit = 8 (Buy at 2, sell at 10)
- Using multiple transactions: Maximum Profit = 11 (Buy at 2, sell at 6; Buy at 3, sell at 10)

## 8. Swapping, Fibonacci Sequence, and Sorting
 Demonstrates swapping methods, Fibonacci sequence generation, and sorting function.

## Description

This program showcases various concepts, including swapping methods, generating the Fibonacci sequence, and sorting function.

## Features

- Swapping Methods: Demonstrates different ways to swap two integers, including correct and incorrect implementations.
- Fibonacci Sequence: Generates the Fibonacci sequence up to a given number using iterative logic.

## Getting Started

1. Clone the repository or download the source code.
2. Compile the `Swapping_Fibonacci_Sorting.c` source file using a C compiler (e.g., gcc).
3. Run the compiled executable to observe the demonstration of swapping methods, Fibonacci sequence generation, and incorrect sorting.

## Contents

- **Swap Functions**: Illustrates swapping two integers using different methods, including correct and incorrect implementations.
- **Fibonacci Sequence Generation**: Generates the Fibonacci sequence using iterative logic up to a given number.

# 9. Palindrome Checker

A program that checks if a number is a palindrome and provides its reversed form.

## Description

This program allows you to input a number and checks whether it's a palindrome. It also provides the reversed form of the input number. The program follows the guidelines of MISRA-C 2012 and adheres to coding standards.

## Features

- Palindrome Check: Determines if a number is a palindrome.
- Reversed Form: Displays the reversed form of the input number.

## Usage

1. Compile the `Palindrome.c` source file.
2. Run the compiled executable.
3. Enter a number to be checked.

## Example

```bash
$ ./Palindrome
Enter a number: 12321
The number is a palindrome.
Reversed: 12321
```












