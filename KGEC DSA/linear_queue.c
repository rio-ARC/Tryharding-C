#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void insert()
{
    int item;
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else
    {
        printf("Enter element to insert: ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
    }
}
void delete()
{
    if (front == -1)
        printf("Queue Underflow!\n");
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}
void display()
{
    if (front == -1)
        printf("Queue is Empty!\n");
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
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
    } while (choice != 4);
    return 0;
}