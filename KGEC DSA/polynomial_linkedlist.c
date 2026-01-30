#include <stdio.h>
#include <stdlib.h>
struct Poly
{
    int coeff, pow;
    struct Poly *next;
};
struct Poly *createNode(int c, int p)
{
    struct Poly *node = (struct Poly *)malloc(sizeof(struct Poly));
    node->coeff = c;
    node->pow = p;
    node->next = NULL;
    return node;
}
struct Poly *insertTerm(struct Poly *head, int c, int p)
{
    struct Poly *newNode = createNode(c, p);
    if (head == NULL || head->pow < p)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Poly *temp = head;
        while (temp->next != NULL && temp->next->pow >= p)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
void display(struct Poly *head)
{
    if (head == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }
    struct Poly *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL && temp->next->coeff >= 0)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Poly *poly = NULL;
    // Example Polynomial: 5x^3 + 4x^2 + 2x + 1
    poly = insertTerm(poly, 5, 3);
    poly = insertTerm(poly, 4, 2);
    poly = insertTerm(poly, 2, 1);
    poly = insertTerm(poly, 1, 0);
    printf("Polynomial Expression:\n");
    display(poly);
    return 0;
}