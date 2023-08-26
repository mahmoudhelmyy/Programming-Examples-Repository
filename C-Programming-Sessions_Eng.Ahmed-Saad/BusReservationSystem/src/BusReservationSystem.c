/*
 * File: BusReservationSystem.c
 * Author: Mahmoud Sayed Helmy
 * Class: 3
 * Instructor: Eng. Ahmed Saad
 * Description: A program for booking and managing trips.
 * MISRA Compliance: Checked and fixed
 * Description : System Requirements
 * Login page ( username, password)
 * Show trips ( Round trip or one direction, time, from & to)
 * Buy ticket (with multiple payment methods & if you have promotion code (discount)
 * Cancel ticket (limited time to cancel it)
 * ============================================================================
 */


#include "SysHeaders.h"
#include <string.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char u_username[20];
	char u_password[20];
	char choice;

	int u_bookID = 0, u_NumberOfSeats = 0;
	printf("========================================\n");
	printf("******  Bus Reservation System  ******\n");
	printf("========================================\n");

	printf("\t\tMahmoud Helmy\n");
	printf("\t\tVersion: 1.0\n\n\n");

	printf("System Description:\n");
	printf(
			"Welcome to the Bus Reservation System. This system\nprovides a convenient way for passengers to reserve\nand cancel bus seats for their travel needs.\n\n\n");
#if (USERTEST_MODES==1)
	tripInit();
	while (!isLogged()) {
		printf("Enter username: ");
		if (scanf("%19s", u_username) != 1) {
			printf("Error reading username.\n");
			return 1;
		}

		printf("Enter password: ");
		if (scanf("%19s", u_password) != 1) {
			printf("Error reading password.\n");
			return 1;
		}
		login(u_username, u_password);
	}

	while (1) {

		printf("==========================\n");
		printf("|| [1] Show trips           ||\n");
		printf("|| [2] Book a trip          ||\n");
		printf("|| [3] cancel a trip        ||\n");
		printf("|| [4] login                ||\n");
		printf("|| [5] logout               ||\n");
		printf("==========================\n");
		printf("Enter your choice: ");
		scanf(" %c", &choice);

		switch (choice) {
		case (SHOW_TRIP):
			showTrips();
			break;
		case (BOOK_TRIP):
			printf("Enter trip ID (0-2): ");
			scanf("%d", &u_bookID);
			printf("Enter Number of seats: ");
			scanf("%d", &u_NumberOfSeats);
			bookTrip(u_bookID, u_NumberOfSeats);
			break;
		case (CANCEL_TRIP):
			printf("Enter trip ID (0-2): ");
			scanf("%d", &u_bookID);
			if (isReserved(u_bookID)) {
				printf("Enter Number of seats: ");
				scanf("%d", &u_NumberOfSeats);
			}
			cancelTrip(u_bookID, u_NumberOfSeats);
			break;
		case (LOGOUT):
			g_loggedSTATUS = LOGGED_OUT;
			printf("LOGGEDOUT :(\n");
			break;

		case (LOGIN):
			if (g_loggedSTATUS == LOGGED_OUT) {
				g_loggedSTATUS = LOGGED_IN;
				printf("LOGGEDIN :)\n");
			} else {
				printf("Already loggedin ;)\n");
			}
			break;
		default:
			printf("Enter valid input\n");
			break;

		}
	}

#elif(USERTEST_MODES==0)
testLogin();
testBookTrip();
testCancelTrip();
#endif

}

/*Function to perform user login
 *@param username: The username provided by the user
 *@param password: The password provided by the user
 */
void login(char *username, char *password) {
	char forgetQuestion;
	g_loggedSTATUS = verifyLogin(username, password);
	if (g_loggedSTATUS == LOGGED_IN) {
		printf("Welcome, ");
		printString(my_username, USERNAME_SIZE);
		printf("\n Login Success\n");
	} else {
		printf("Invalid credentials\n");
		printf("\nforget password? y/n\n");
		scanf(" %c", &forgetQuestion);
		if (forgetQuestion == 'y' || forgetQuestion == 'Y') {
			printf("\nEnter new username: ");
			scanf("%s", my_username);
			printf("\nEnter new password:  \n");
			scanf("%s", my_password);
			/*			printf("your username: ");
			 printString(my_username, USERNAME_SIZE);
			 printf("\n");
			 printf("your password: ");
			 printString(my_password, PASSWORD_SIZE);
			 printf("\n");*/
		} else if (forgetQuestion == 'N' || forgetQuestion == 'n') {
			return;
		}

	}
}

/* Function to verify user login credentials
 * @param v_username: The username to be verified
 * @param v_password: The password to be verified
 * @return: Returns LOGGED_IN if the credentials are valid, otherwise returns FAILURE
 */
int verifyLogin(char *v_username, char *v_password) {
	int i = 0;
	int valid_credentials = LOGGED_IN;

	while (v_username[i] != '\0' && my_username[i] != '\0') {
		if (v_username[i] != my_username[i]) {
			valid_credentials = FAILURE;
			break;
		}
		i++;
	}

	i = 0;
	while (v_password[i] != '\0' && my_password[i] != '\0') {
		if (v_password[i] != my_password[i]) {
			valid_credentials = FAILURE;
			break;
		}
		i++;
	}

	return valid_credentials;
}

/* Function to check if a user is logged in
 * @return: Returns 1 if the user is logged in, 0 otherwise
 */

int isLogged() {
	if (g_loggedSTATUS == LOGGED_IN) {
		return 1;
	} else {
		return 0;
	}
}

/*
 * Initialize trip data
 */
void tripInit() {
	avaliableTrip[Dahab].destination = "Dahab";
	avaliableTrip[Dahab].tripID = 0;
	avaliableTrip[Dahab].AvailableSeats = MAX_SEATS;
	avaliableTrip[Dahab].tripDate = "2023/7/10";
	avaliableTrip[AinSokhna].destination = "AinSokhna";
	avaliableTrip[AinSokhna].tripID = 1;
	avaliableTrip[AinSokhna].AvailableSeats = MAX_SEATS;
	avaliableTrip[AinSokhna].tripDate = "2023/3/24";

	avaliableTrip[Hurghada].destination = "Hurghada";
	avaliableTrip[Hurghada].tripID = 2;
	avaliableTrip[Hurghada].AvailableSeats = MAX_SEATS;
	avaliableTrip[Hurghada].tripDate = "2023/7/12";
}

/*
 * Display available trips
 */
void showTrips() {
	if (g_loggedSTATUS == LOGGED_IN) {
		printf("======= Our Trips ======== \n");
		printf("[%d] ", avaliableTrip[Dahab].tripID);
		printString(avaliableTrip[Dahab].destination, 5);
		printf("\tAvaliable seats = %d \n",
				avaliableTrip[Dahab].AvailableSeats);
		printf("\n");

		printf("[%d] ", avaliableTrip[AinSokhna].tripID);
		printString(avaliableTrip[AinSokhna].destination, 9);
		printf("\tAvaliable seats = %d \n",
				avaliableTrip[AinSokhna].AvailableSeats);
		printf("\n");

		printf("[%d] ", avaliableTrip[Hurghada].tripID);
		printString(avaliableTrip[Hurghada].destination, 8);
		printf("\tAvaliable seats = %d \n",
				avaliableTrip[Hurghada].AvailableSeats);
		printf("\n");

	} else if (g_loggedSTATUS == LOGGED_OUT) {
		printf("you have to login first !\n");
	}
}

/*Book a trip
 *@param u_tripID: The ID of the trip to be booked (0-2)
 *@param u_SeatNumbers: The number of seats to be booked
 */

void bookTrip(int u_tripID, int u_SeatNumbers) {
	if (g_loggedSTATUS == LOGGED_IN) {

		switch (u_tripID) {
		case Dahab:
		case AinSokhna:
		case Hurghada:
			if ((avaliableTrip[u_tripID].AvailableSeats) >= u_SeatNumbers) {
				avaliableTrip[u_tripID].AvailableSeats -= u_SeatNumbers;
				confirmationID[u_tripID] = VALID;
				printf("Booking successful!\n");
			} else {
				printf("Insufficient seats available.\n");
			}
			break;
		default:
			printf("Invalid Trip ID.\n");
			break;
		}
	} else {
		printf("You need to be logged in to book a trip.\n");
	}
}
/*Check if a trip is reserved
 * @param tripID: The ID of the trip to be checked
 * @return: Returns 1 if the trip is reserved, 0 otherwise
 */
int isReserved(int tripID) {
	if (confirmationID[tripID] == VALID) {
		return 1;
	} else {
		return 0;
	}
}

/*Cancel a booked trip
 *@param c_tripID: The ID of the trip to be canceled (0-2)
 *@param c_SeatNumbers: The number of seats to be canceled
 */
void cancelTrip(int c_tripID, int c_SeatNumbers) {
	if (g_loggedSTATUS == LOGGED_IN) {
		if (isReserved(c_tripID)) {
			switch (c_tripID) {
			case Dahab:
			case AinSokhna:
			case Hurghada:
				if ((avaliableTrip[c_tripID].AvailableSeats)
						+ c_SeatNumbers<= MAX_SEATS) {
					avaliableTrip[c_tripID].AvailableSeats += c_SeatNumbers;
					printf("Canceled successful!\n");
					printf("we wish to meet you again :D\n");
				} else {
					printf("INVALID input\n");
				}
				break;
			default:
				printf("Invalid Trip ID.\n");
				break;
			}
		} else if (!isReserved(c_tripID)) {
			printf("no reservation\n");
		} else {
			printf("You need to be logged in to book a trip.\n");
		}
	}
}
/*
 * ======================== test functions ================================
 */
// Function to test the cancelTrip function
void testCancelTrip() {
	// Simulate a loggedin user
	g_loggedSTATUS = LOGGED_IN;

	// Test Case 1: Cancel a reserved trip with valid seat numbers
	int tripID1 = Dahab;
	int seatNumbers1 = 2;
	confirmationID[tripID1] = VALID;
	avaliableTrip[tripID1].AvailableSeats = MAX_SEATS - seatNumbers1;
	cancelTrip(tripID1, seatNumbers1);

	// Test Case 2: Cancel a non-reserved trip
	int tripID2 = AinSokhna;
	int seatNumbers2 = 1;
	cancelTrip(tripID2, seatNumbers2);

	// Test Case 3: Cancel a reserved trip with invalid seat numbers
	int tripID3 = Hurghada;
	int seatNumbers3 = 10;
	confirmationID[tripID3] = VALID;
	avaliableTrip[tripID3].AvailableSeats = MAX_SEATS - seatNumbers3;
	cancelTrip(tripID3, seatNumbers3);

	// Test Case 4: Cancel a trip without being logged in
	g_loggedSTATUS = LOGGED_OUT;
	int tripID4 = Dahab;
	int seatNumbers4 = 1;
	cancelTrip(tripID4, seatNumbers4);
}

// Function to test the bookTrip function
void testBookTrip() {
	// Simulate a logged-in user
	g_loggedSTATUS = LOGGED_IN;

	// Test Case 1: Booking a trip with sufficient available seats
	int tripID1 = Dahab;
	int seatNumbers1 = 3;
	printf("Booking Test Case 1:\n");
	printf("Before booking: Available seats for %s = %d\n",
			avaliableTrip[tripID1].destination,
			avaliableTrip[tripID1].AvailableSeats);
	bookTrip(tripID1, seatNumbers1);
	printf("After booking: Available seats for %s = %d\n",
			avaliableTrip[tripID1].destination,
			avaliableTrip[tripID1].AvailableSeats);

	// Test Case 2: Booking a trip with insufficient available seats
	int tripID2 = AinSokhna;
	int seatNumbers2 = 10;
	printf("Booking Test Case 2:\n");
	printf("Before booking: Available seats for %s = %d\n",
			avaliableTrip[tripID2].destination,
			avaliableTrip[tripID2].AvailableSeats);
	bookTrip(tripID2, seatNumbers2);
	printf("After booking: Available seats for %s = %d\n",
			avaliableTrip[tripID2].destination,
			avaliableTrip[tripID2].AvailableSeats);

	// Test Case 3: Booking a trip with an invalid trip ID
	int tripID3 = 5;
	int seatNumbers3 = 2;
	printf("Booking Test Case 3:\n");
	bookTrip(tripID3, seatNumbers3);

	// Test Case 4: Booking a trip without being logged in
	g_loggedSTATUS = LOGGED_OUT;
	int tripID4 = Hurghada;
	int seatNumbers4 = 1;
	printf("Booking Test Case 4:\n");
	bookTrip(tripID4, seatNumbers4);
}
// Function to test the login function
void testLogin() {
	char test_username[USERNAME_SIZE];
	char test_password[PASSWORD_SIZE];

	// Test Case 1: Successful login
	printf("Login Test Case 1:\n");
	strcpy(test_username, "username1");  // Replace with valid username
	strcpy(test_password, "password1");  // Replace with valid password
	login(test_username, test_password);

	// Test Case 2: Failed login
	printf("Login Test Case 2:\n");
	strcpy(test_username, "invalid_user");  // Replace with invalid username
	strcpy(test_password, "invalid_pass");  // Replace with invalid password
	login(test_username, test_password);

	// Test Case 3: Password recovery
	printf("Login Test Case 3 (Password Recovery):\n");
	strcpy(test_username, "username2");  // Replace with valid username
	strcpy(test_password, "password2");  // Replace with valid password
	// Simulate forgetting password
	char forget_response = 'y';
	printf("\nforget password? y/n\n");
	scanf(" %c", &forget_response);
	if (forget_response == 'y' || forget_response == 'Y') {
		login(test_username, test_password);  // Initiate password recovery
	}
}

