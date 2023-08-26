/*
 * File: SysHeaders.h
 * Author: Mahmoud Sayed Helmy
 * Class: 3
 * Instructor: Eng. Ahmed Saad
 * Description: A program for booking and managing trips.
 * MISRA Compliance: Checked and fixed
 */

#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define LOGGED_IN      1
#define LOGGED_OUT     0
#define FAILURE        0
#define VALID          1
#define INVALID        0
#define NumberOfTrips  3
#define Dahab          0
#define AinSokhna      1
#define Hurghada       2
#define MAX_SEATS      10
#define USERNAME_SIZE  5
#define PASSWORD_SIZE  8
#define BOOK_TRIP      '2'
#define SHOW_TRIP      '1'
#define CANCEL_TRIP    '3'
#define LOGOUT         '5'
#define LOGIN          '4'
#define USERTEST_MODES 1

/* Global Variables */
int g_loggedSTATUS = LOGGED_OUT;
int confirmationID[NumberOfTrips] = { INVALID };
char my_username[] = "helmy";
char my_password[] = "22326423";

/* Data Structure for Trip */
typedef struct trip {
    int tripID;
    int availableSeats;
    int seatID;
    char *destination;
    char *tripDate;
} trip_type;

/* Function Prototypes */
int verifyLogin(char *v_username, char *password);
void login(char *username, char *password);
void showTrips();
void bookTrip(int u_tripID, int u_SeatNumbers);
void tripInit();
int isLogged();
int isReserved(int tripID);
void cancelTrip(int c_tripID, int c_SeatNumbers);
void printString(char *arr, int size);



/* Other Functions */
void printString(char *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%c", arr[i]);
    }
}


