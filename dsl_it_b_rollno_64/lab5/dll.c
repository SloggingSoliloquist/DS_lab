#include<stdio.h>
#include<stdlib.h>

struct node{
int val;
struct node *prev;
struct node *next;
};
void insert_before_el(struct node **head, struct node **tail, int before_el, int el)
{
    if(*head==NULL)
    {
        printf("No element to insert before");
        return;
    }
    if((*head)->val==before_el)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->val = el;
        temp->prev = NULL;
        temp->next = *head;
        *head = temp;
        *tail= temp;
        return;
    }
    struct node *current = *head;
    while(current->next->val!=before_el)
    {
        current=current->next;
        if(current->next==NULL)
        {
            printf("Element not found in the list");
            return;
        }
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = el;
    temp->prev= current;
    temp->next =current->next;
    current->next = temp;
    temp->next->prev = temp;
    
}
void insert_after_el(struct node *head, struct node **tail, int after_el, int el)
{
    if(head==NULL)
    {
        printf("No element to insert after.");
        return;
    }
    struct node *current = head;
    while(current!=NULL)
    {
        if(current->val==after_el)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->val = el;
            temp->prev = current;
            temp->next= current->next;
            current->next= temp;
            if(temp->next==NULL)
                *tail=temp;
            else{
                temp->next->prev = temp;
            }
            return;
        }
        current = current->next;
    }
    printf("Element not found in the list");
}
void pop_dll(struct node **head, struct node **tail)
{
    if(*head==NULL)
    {
        return;
    }
    if((*head)->next==NULL)
    {
        free((*head)->next);
        free((*head)->prev);
        *head = NULL;
        free((*tail)->next);
        free((*tail)->prev);
        *tail = NULL;
        return;
    }
    struct node *current = *head;
    while(current->next->next!=NULL)
    {
        current = current->next;
    }
    struct node *temp=current->next;
    current->next=current->next->next;
    free(temp);
    *tail = current;
}
void append_dll(struct node **head, struct node **tail, int el)
{
    if(*head==NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->prev= NULL;
        temp->next=NULL;
        temp->val = el;
        *head = temp;
        return;
    }
    struct node *current = *head;
    while (current->next!=NULL)
    {
     current = current->next;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = el;
    temp->prev = current;
    temp->next = NULL;
    current->next = temp;
    *tail= temp;
}

void insert_node_by_pos(struct node **head, struct node **tail, int pos, int el)
{
    if(pos==0 || pos==1)
    {
        if(*head==NULL)
        {
            *head = (struct node *)malloc(sizeof(struct node));
            (*head)->val = el;
            (*head)->next= NULL;
            (*head)->prev=NULL;
            *tail = *head;
            return;
        }
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->val= el;
        temp->prev  = NULL;
        temp->next = *head;
        *head = temp;

        return;
    }

        struct node *current = (struct node *)malloc(sizeof(struct node));
        current =*head;
        for(int i = 1; i<pos-1; i++)
        {
            current = current->next;
            if (current==NULL)
            {
                printf("The element is not present in the list: ");
                return;
            }
        }
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->val= el;
        temp->prev  = current;
        temp->next = current->next;
        current->next = temp;

        if(temp->next==NULL)
        {
            *tail = temp;
        }
        else
        temp->next->prev = temp;
    }
void delete_from_pos(struct node **head, struct node **tail, int pos)
{
    if(*head==NULL)
    {
        return;
    }
    if (pos==1)
    {
        if((*head)->next==NULL)
        {
            free((*head)->next);
            free((*head)->prev);
            *head = NULL;
            *tail = NULL;
            return;
        }
        else{
            struct node *temp = (*head);
            *head= (*head)->next;
            (*head)->prev = NULL;
            free(temp);
            return;

        }
    }
    struct node *current = *head;
    for(int i =1; i<pos-1;i++)
    {
        current= current->next;
        if(current==NULL)
        {
            printf("Position does not exist in the list");
            return;
        }
    }
    if (current->next==NULL)
    {
        printf("Cannot delete at this position\n");
        return;
    }
    struct node *temp = current->next;
    if(current->next->next!=NULL)
    {
    current->next= current->next->next;
    current->next->prev = current;
    }
    else{
    current->next = NULL;
    *tail = current;}
    free(temp);

}
void display_dll(struct node *head)
{
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    struct node *current = head;
    while(current!=NULL)
    {
        printf("%d->", current->val);
        current = current->next;
    }
    printf("NULL");
}
void display_reverse(struct node *tail)
{
    struct node *current = tail;
    while(current!=NULL)
    {
        printf("%d->", current->val);
        current= current->prev;
    }
    printf("NULL");
}
void create_dll(struct node **head, struct node **tail, int len)
{
    if(len==0)
    {
        *head=NULL;
        *tail = NULL;
        return;
    }
    *head= (struct node*)malloc(sizeof(struct node));
    (*head)->prev= NULL;
    struct node *current = *head;
    for(int i = 0; i<len; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &current->val);
        if(i!=len-1)
        {
            current->next = (struct node *)malloc(sizeof(struct node));
            current->next->prev=current;
            current = current->next;

        }
        else
        {
            *tail = current;
            current->next=NULL;}
    }

}
int main()
{
    int l,el, choice,pos, flag =0;
    struct node *head= NULL;
    struct node *tail=NULL;
    while(flag==0){
        printf("\nEnter 1 to create a linked list,\n 2 to display,\n3 to append,\n4 to pop a linked list,\n5 to insert by position,\n6 to delete by position,\n");
        printf("7 to insert after an element,\n8 to insert before an element,\n9to display the list in reverse,\n10 to exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the length of the linked list: ");
            scanf("%d", &l);
            create_dll(&head, &tail, l);
            break;
        case 2:
            printf("The list is: ");
            display_dll(head);
            break;
        case 3:
            printf("Enter the element you want to append: ");
            scanf("%d", &el);
            append_dll(&head, &tail, el);
            display_dll(head);
            break;
        case 4:
            pop_dll(&head, &tail);
            display_dll(head);
            break;
        case 5:
            printf("Enter the position into which you want to insert :");
            scanf("%d", &pos);
            printf("Enter the element you want to insert: ");
            scanf("%d", &el);
            insert_node_by_pos(&head, &tail, pos, el);
            display_dll(head);
            break;
        case 6:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            delete_from_pos(&head, &tail, pos);
            display_dll(head);
            break;
        case 7:
            printf("Enter the element after which to insert: ");
            scanf("%d", &pos);
            printf("Enter the element you want to insert: ");
            scanf("%d", &el);
            insert_after_el(head, &tail, pos, el);
            display_dll(head);
            break;
        case 8:
            printf("Enter the element before which you want to insert: ");
            scanf("%d", &pos);
            printf("Enter the element you want to insert: ");
            scanf("%d", &el);
            insert_before_el(&head, &tail, pos, el);
            display_dll(head);
            break;
        case 9:
            display_reverse(tail);
            break;
        case 10:
        flag = 1;
        break;
        }

    }
return 0;}
