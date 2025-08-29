#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *prev;
    struct node *next;
};

void create_dll(struct node **head, struct node **tail, int len)
{
    if (len == 0) {
        *head = NULL;
        *tail = NULL;
        return;
    }

    *head = (struct node*)malloc(sizeof(struct node));
    (*head)->prev = NULL;

    struct node *current = *head;

    for (int i = 0; i < len; i++) {
        printf("Enter the element: ");
        scanf("%d", &current->val);

        if (i != len - 1) {
            current->next = (struct node*)malloc(sizeof(struct node));
            current->next->prev = current;
            current = current->next;
        } else {
            *tail = current;
            current->next = NULL;
        }
    }
}

void concatenate(struct node **head1, struct node **tail1,
                 struct node **head2, struct node **tail2)
{
    if (*head1 == NULL) {
        *head1 = *head2;
        *tail1 = *tail2;
    } else if (*head2 != NULL) {
        (*tail1)->next = *head2;
        (*head2)->prev = *tail1;
        *tail1 = *tail2; 
    }

}

void print_forward(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void print_backward(struct node *tail)
{
    struct node *temp = tail;
    while (temp != NULL) {
        printf("%d->", temp->val);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head1, *tail1;
    struct node *head2, *tail2;
    int len1, len2;

    printf("Enter number of elements in first list: ");
    scanf("%d", &len1);
    create_dll(&head1, &tail1, len1);

    printf("Enter number of elements in second list: ");
    scanf("%d", &len2);
    create_dll(&head2, &tail2, len2);

    printf("\nList 1 forward: ");
    print_forward(head1);
    printf("List 1 backward: ");
    print_backward(tail1);

    printf("\nList 2 forward: ");
    print_forward(head2);
    printf("List 2 backward: ");
    print_backward(tail2);

    concatenate(&head1, &tail1, &head2, &tail2);

    printf("\nAfter concatenation:\n");
    printf("List 1 forward: ");
    print_forward(head1);
    printf("List 1 backward: ");
    print_backward(tail1);


    return 0;
}
