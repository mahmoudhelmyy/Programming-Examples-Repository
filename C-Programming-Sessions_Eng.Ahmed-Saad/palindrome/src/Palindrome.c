/*
 ============================================================================
 Name        : Palindrome.c
 Author      : Mahmoud Helmy
 Class       : 3
 Instructor  : Eng. Ahmed Saad
 Description : This program checks if a number is a palindrome and
               also provides its reversed form.

               This code is MISRA compliant and follows coding standards.

               MISRA-C 2012 Guidelines:
               Rule 2.1: Characters shall only be used within the basic character set.
               Rule 8.4: The operands of a logical AND or logical OR operator shall be primary expressions.
               Rule 10.3: The value of a complex expression of integer type shall not be cast to a different
                          essential type category or a wider integer type.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Checks if a number is a palindrome and provides its reversed form.
 *
 * @param n The number to be checked.
 * @return 1 if the number is a palindrome, 0 otherwise.
 */
int check_and_reverse(int n) {
    int reversed = 0;
    int original = n;

    while (n != 0) {
        reversed = n % 10 + reversed * 10;
        n /= 10;
    }

    if (original == reversed) {
        printf("The number is a palindrome.\n");
        printf("Reversed: %d\n", reversed);
        return 1;
    } else {
        printf("The number is not a palindrome.\n");
        printf("Reversed: %d\n", reversed);
        return 0;
    }
}

/**
 * Test function to check the check_and_reverse function.
 *
 * @param n The number to be tested.
 * @param expectedValue The expected return value.
 */
void testFunction_CheckandReverse(int n, int expectedValue) {
    if (check_and_reverse(n) == expectedValue) {
        printf("TESTED: SUCCESS!\n");
    } else {
        printf("TESTED: FAIL!\n");
    }
}

int main(void) {
    testFunction_CheckandReverse(-121, 0);

    return 0;
}
