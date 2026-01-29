#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insert()
{
    int x;
    printf("Enter element to insert: ");
    scanf("%d", &x);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void delete()
{
    int x;
    printf("Enter element to delete: ");
    scanf("%d", &x);
    struct Node *temp = head, *prev = NULL;
    while (temp != NULL && temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        printf("Element not found!\n");
    else
    {
        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;
        free(temp);
        printf("Element deleted!\n");
    }
}
void display()
{
    if (head == NULL)
        printf("List is empty!\n");
    else
    {
        struct Node *temp = head;
        printf("Linked List: ");
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
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
    } while (ch != 4);
    return 0;
}
