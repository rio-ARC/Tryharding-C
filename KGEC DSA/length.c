#include <stdio.h>
#include <string.h> // Required for strcspn to remove the newline from fgets

// Recursive function to calculate the length of a string.
// str: a pointer to the beginning of the string.
// Returns the length of the string.
int recursiveStringLength(const char *str) {
    // Base case: If the current character is the null terminator ('\0'),
    // we have reached the end of the string. The length of an empty string is 0.
    if (*str == '\0') {
        return 0;
    }
    // Recursive step: If it's not the end of the string, the length is 1
    // (for the current character) plus the length of the rest of the string.
    // We call the function again with the next character in the string (str + 1).
    else {
        return 1 + recursiveStringLength(str + 1);
    }
}

// Main function to drive the program
int main() {
    char inputString[100]; // Declare a character array to store the string

    // Prompt the user to enter a string
    printf("Enter a string: ");

    // Read the string from the user, including spaces.
    // fgets is safer than scanf for strings.
    if (fgets(inputString, sizeof(inputString), stdin) != NULL) {
        // fgets includes the newline character in the buffer, so we remove it.
        // strcspn finds the first occurrence of a character in the set "\n".
        inputString[strcspn(inputString, "\n")] = '\0';

        // Call the recursive function to find the length
        int length = recursiveStringLength(inputString);

        // Print the result
        printf("The length of the string \"%s\" is %d.\n", inputString, length);
    }

    return 0; // Indicate successful execution
}
