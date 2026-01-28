#include <stdio.h>
#define MAX 5
int cq[MAX];
int front = -1, rear = -1;
void insert()
{
    int item;
    if ((rear + 1) % MAX == front)
        printf("Circular Queue Overflow!\n");
    else
    {
        printf("Enter element to insert: ");
        scanf("%d", &item);
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;
        cq[rear] = item;
    }
}
void delete()
{
    if (front == -1)
        printf("Circular Queue Underflow!\n");
    else
    {
        printf("Deleted element: %d\n", cq[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}
void display()
{
    if (front == -1)
        printf("Queue is Empty!\n");
    else
    {
        printf("Circular Queue elements: ");
        int i = front;
        while (1)
        {
            printf("%d ", cq[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n--- Circular Queue Menu ---\n");
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
