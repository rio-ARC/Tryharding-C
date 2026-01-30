#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue()
{
    int x;
    printf("Enter element: ");
    scanf("%d", &x);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void dequeue()
{
    if (front == NULL)
        printf("Queue Empty!\n");
    else
    {
        printf("Deleted: %d\n", front->data);
        struct Node *temp = front;
        front = front->next;
        free(temp);
        if (front == NULL)
            rear = NULL;
    }
}
void display()
{
    if (front == NULL)
        printf("Queue Empty!\n");
    else
    {
        struct Node *temp = front;
        printf("Queue: ");
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
        printf("\n--- Queue Menu ---\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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