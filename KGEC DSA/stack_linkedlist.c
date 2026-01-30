#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void push()
{
    int x;
    printf("Enter element to push: ");
    scanf("%d", &x);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}
void pop()
{
    if (top == NULL)
        printf("Stack Underflow!\n");
    else
    {
        printf("Popped: %d\n", top->data);
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
}
void display()
{
    if (top == NULL)
        printf("Stack Empty!\n");
    else
    {
        struct Node *temp = top;
        printf("Stack elements: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n--- Stack Menu ---\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (ch != 4);
    return 0;
}