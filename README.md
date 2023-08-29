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







