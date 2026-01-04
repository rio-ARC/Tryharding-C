#include <stdio.h>

int main()
{
    int choice;
    float num1, num2, result;

    while (1)
    {

        printf("* Simple Calculator *\n");
        printf("1: Perform Addition \n");
        printf("2: Perform Subtraction \n");
        printf("3: Perform Multiplication \n");
        printf("4: Perform Division \n");
        printf("5: To Exict the Calculator \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            printf("Exiting Calculator...");
            break;
        }

        printf("Enter the first number: ");
        scanf("%f", &num1);
        printf("Enter the second number: ");
        scanf("%f", &num2);

        if (choice == 1)
        {
            result = num1 + num2;
            printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
        }
        else if (choice == 2)
        {
            result = num1 - num2;
            printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
        }
        else if (choice == 3)
        {
            result = num1 * num2;
            printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
        }
        else if (choice == 4)
        {
            if (num2 == 0)
                printf("Error: Can't divide by zero.\n");
            else
            {
                result = num1 / num2;
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
            }
        }
        else
            printf("Invalid choice\n");
    }
    return 0;
}
