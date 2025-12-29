#include <stdio.h>
#include <stdbool.h> // Include for boolean type (true/false)
#include <math.h>    // Include for sqrt() function for optimization

// Function to check if a number is prime.
// n: the integer to check.
// Returns true if n is prime, false otherwise.
bool isPrime(int n) {
    // Prime numbers must be greater than 1.
    // 0, 1, and negative numbers are not prime.
    if (n <= 1) {
        return false;
    }

    // A number is prime if it is not divisible by any integer other than 1 and itself.
    // We can optimize by checking for divisors only up to the square root of n.
    // If n has a divisor larger than its square root, it must also have a
    // corresponding divisor smaller than its square root.
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        // If n is divisible by any number in this range, it's not prime.
        if (n % i == 0) {
            return false; // Found a divisor, so not prime.
        }
    }

    // If the loop completes without finding any divisors, the number is prime.
    return true;
}

// Main function to drive the program
int main() {
    int number;

    // Prompt the user to enter a positive integer
    printf("Enter a positive integer to check if it's prime: ");
    scanf("%d", &number);

    // Call the isPrime function and check its return value
    if (isPrime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0; // Indicate successful execution
}
