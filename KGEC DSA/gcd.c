#include <stdio.h>

// Function to find the Greatest Common Divisor (GCD) of two numbers
// This function uses the Euclidean algorithm recursively.
// a: The first integer
// b: The second integer
// Returns the GCD of a and b
int findGCD(int a, int b) {
    // The base case for the recursion: if b is 0, then a is the GCD.
    if (b == 0) {
        return a;
    }
    // The recursive step: call the function again with b and the remainder of a divided by b.
    // The algorithm relies on the principle that gcd(a, b) = gcd(b, a % b).
    else {
        return findGCD(b, a % b);
    }
}

// Main function to drive the program
int main() {
    int num1, num2;

    // Prompt the user to enter two positive integers
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    // Ensure the inputs are positive, as GCD is typically defined for positive integers.
    if (num1 <= 0 || num2 <= 0) {
        printf("Please enter positive integers only.\n");
        return 1; // Exit with an error code
    }

    // Call the findGCD function and store the result
    int result = findGCD(num1, num2);

    // Print the result to the console
    printf("The GCD of %d and %d is %d.\n", num1, num2, result);

    return 0; // Indicate successful execution
}
