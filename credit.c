#include <stdio.h>
#include <string.h>

int isOdd(int num);
int isEven(int num);

int main(void) {
    int product, total = 0; // Initialize total to 0
    int number;
    char cardnum[17]; // Declare a character array to store up to 16 digits + null terminator

    printf("Card Number: ");

    if (scanf("%s", cardnum) != 1) { // Check if scanf successfully reads one string
        printf("Error: Invalid input.\n");
        return 1; // Return a non-zero value to indicate an error
    }
    
    // Check the length of the card number input
    int length = strlen(cardnum);
    if (length != 13 && length != 15 && length != 16) {
        printf("Invalid input\n");
        return 2; // Exit if the input is not valid
    }
    
    printf("%d\n", length); // Print the length of the card number

    // Loop through the length and process the digits
    for (int i = 0; i < length; i++) {
        int digit = cardnum[i] - '0'; // Convert character to integer
        
        if (isEven(length - i)) { // Check if the index is odd based on position from the end
            product = digit * 2; // Multiply by 2     // THIS MIGHT NOT WORK BASED ON WHAT YOU ARE REALLY TRYING TO DO //
            // Add the digits of product to total     // READ CAREFULLY ABOUT WHAT IS BEING ASKED // it only asks to mulitply every other, not ever even or odd number.
            total += (product / 10) + (product % 10); // Sum the digits of the product
        } else { 
            total += digit; // Add the digit to total
        }
    }

    // // Check if the total's last digit is 0
    // if (total % 10 == 0) {
    //     printf("The number is valid.\n");            Produced by AI - Learn before proceeding.
    // } else {
    //     printf("The number is invalid.\n");
    // }

    return 0; // Successful execution
}

// Function to check if a number is odd
int isOdd(int num) {
    return num % 2 != 0; // Return 1 if odd, 0 if even
}

// Function to check if a number is even
int isEven(int num) {
    return num % 2 == 0; // Return 1 if even, 0 if odd
}
