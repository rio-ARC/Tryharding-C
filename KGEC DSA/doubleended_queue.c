#include <stdio.h>
#define MAX 5
int deque[MAX];
int front = -1, rear = -1;
void insertFront()
{
    int x;
    printf("Enter element to insert at front: ");
    scanf("%d", &x);
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        printf("Deque Overflow!\n");
    else if (front == -1)
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;
    deque[front] = x;
}
void insertRear()
{
    int x;
    printf("Enter element to insert at rear: ");
    scanf("%d", &x);
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        printf("Deque Overflow!\n");
    else if (front == -1)
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;
    deque[rear] = x;
}
void deleteFront()
{
    if (front == -1)
        printf("Deque Underflow!\n");
    else
    {
        printf("Deleted from front: %d\n", deque[front]);
        if (front == rear)
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
}
void deleteRear()
{
    if (front == -1)
        printf("Deque Underflow!\n");
    else
    {
        printf("Deleted from rear: %d\n", deque[rear]);
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }
}
void display()
{
    if (front == -1)
        printf("Deque is Empty!\n");
    else
    {
        printf("Deque elements: ");
        int i = front;
        while (1)
        {
            printf("%d ", deque[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n--- DEQUE Menu ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertFront();
            break;
        case 2:
            insertRear();
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (ch != 6);
    return 0;
}
