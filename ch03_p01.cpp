#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>

/*
 * Name: Trevor Benyack
 * Date: 2020-05-30
 * Class: CIT-145-Z01B
 * Notes: This is an encryption and decryption program. The user can choose to encrypt or decrypt a four-digit integer,
 * and have the result displayed back to them.
 */

// This function converts each digit of the input integer into a single element of an array. The function then
// performs either an encryption or decryption of the array, based on the user's choice.
void intToArray(int numbers[], int input, int menuChoice) {

    int divisor = 1; // holds which magnitude of 10 to divide the input number by.

    // The integer is broken down into individual digits via base-10 deconstruction.
    for (int i = 0; i < 4; ++i) {
        divisor *= 10;
        numbers[i] = input % divisor; // initial assignment for each power of 10
        input -= numbers[i]; // removes the remainder from the original number
        if (numbers[i] != 0) { // accounts for 0 as one of the digits in the number
            numbers[i] /= (divisor / 10); // reduces the remainder to a single digit
        }

        // Encryption/Decryption occurs here
        if (menuChoice == 1) {
            numbers[i] += 7;
            numbers[i] %= 10;
        } else if (menuChoice == 2) {
            if (numbers[i] <= 9 && numbers[i] >= 7) {
                numbers[i] -= 7;
            }
            else {
                numbers[i] += 3;
            }
        } // end userChoice conditional
    } // end for loop
} // end intToArray function

// Swaps the positions 3,1 and 2,4 of the encrypted number.
void numbersSwap(int numbers[]) {
    int temp = 0;
    temp = numbers[3];
    numbers[3] = numbers[1];
    numbers[1] = temp;

    temp = numbers[2];
    numbers[2] = numbers[0];
    numbers[0] = temp;

}

int main(void) {

    int input = 0;
    int numbers[] = { 0, 0, 0, 0 };
    int menuChoice = 0;
    int repeat = 1;
    while (repeat == 1) {
        // Prompts user to choose encode/decode and input an integer
        printf("%s", "Encode (1) Decode (2): ");
        scanf("%d", &menuChoice);
        printf("%s", "Enter a four digit number: ");
        scanf("%d", &input);

        // Function calls to encrypt/decrypt and to swap numbers
        intToArray(numbers, input, menuChoice);
        numbersSwap(numbers);

        // Prints the result to the user
        menuChoice == 1 ? printf("%s", "Encoded") : printf("%s", "Decoded");
        printf(" Digits: %d%d%d%d", numbers[3], numbers[2], numbers[1], numbers[0]);
        printf("%s", "\nContinue (1) Exit (0): ");
        scanf("%d", &repeat);
    }

    system("pause");
    return 0;
}
