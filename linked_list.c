
#include<stdio.h>
#include<stdlib.h>
struct node{
int val;
struct node *next;

};

void insert_into_sorted_order(struct node **head, int el)
{
    if((*head)==NULL)
    {
        return;
    }
    if((*head)->next==NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->val= el;
        if((*head)->val<el)
        {
            temp->next=NULL;
            (*head)->next = temp;
        }
        else
        {
            temp->next=*head;
        }
        return;
    }
    struct node *current = *head;
    while(current->next!=NULL)
    {
        if(current->val<el && current->next->val>el)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->val = el;
            temp->next = current->next;
            current->next = temp;
            return;
        }
    }
}
void sort_linked_list(struct node **head)
{
    if((*head)==NULL||(*head)->next==NULL)
        return;
    int temp;
    int list_len=0;
    struct node *current = *head;
    while(current!=NULL)
    {
        current = current->next;
        list_len++;
    }
    printf("%d", list_len);
    current = *head;

    for(int i=list_len-1; i>=0; i--)
    {
        for(int j=0; j<i-1;j++)
        {
            if(current->val>current->next->val)
            {
                temp = current->val;
                current->val = current->next->val;
                current->next->val = temp;
            }
            current = current->next;
        }
        current=*head;
    }
}

void delete_alternate_node(struct node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    struct node *current= head;
    while(current->next!=NULL)
    {
        struct node *temp =current->next;
        if(current->next->next==NULL)
        {
            free(current->next->next);
            current->next=NULL;
            break;
        }

        current->next = current->next->next;
        free(temp);
        current = current->next;
    }
}
void reverse_linked_list(struct node **head)
{
    if((*head)==NULL || (*head)->next==NULL)
    {
        return;
    }
    struct node *prev=NULL;
    struct node *current = *head;
    struct node *next;
    while(next!=NULL)
    {
        next = current->next;
        current->next= prev;
        prev=current;
        if(next!=NULL)
        current=next;

    }
    *head = current;

}
void delete_el(struct node **head, int del_el)
{
    if((*head)==NULL)
    {
        return;
    }
    if((*head)->next==NULL)
    {
        if((*head)->val==del_el)
        {
            free((*head)->next);
            *head=NULL;
            return;
        }
        else
            return;
    }
    if((*head)->val==del_el)
        {
            struct node *temp = *head;
            *head=(*head)->next;
            free(temp);
            return;
        }
    struct node *current = (struct node*)malloc(sizeof(struct node));
    current = *head;
    while(current->next->val!=del_el)
    {
        current= current->next;
        if(current->next==NULL)
        {
            printf("Element not found in the list: ");
            return;
        }
    }
    struct node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}
void insert_after_el(struct node *head, int after_el, int el)
{
    if (head ==NULL)
    {
        return;
    }
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current = head;
    while(current!=NULL)
    {
        if(current->val==after_el)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->val = el;
            temp->next = current->next;
            current->next = temp;
            return;
        }
        current=current->next;
    }
    printf("The element is not found: ");
    return;
}
void insert_before_el(struct node **head, int before_el, int el)//before_el is the element before which you wnat to insert and el is the other one
{
    if ((*head)==NULL)
    {
        printf("The list is empty");
        return;
    }
    if((*head)->val==before_el)
        {
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->val = el;
            temp->next = *head;
            *head= temp;
            return;
    }
    if((*head)->next==NULL)
    {
        return;
    }
    struct node *current= *head;
    while(current->next->val!=before_el)
    {
        current=current->next;
        if(current->next==NULL)
        {
            printf("Element not found in the list: ");
            return;
        }
    }
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp ->val = el;
    temp->next = current->next;
    current->next = temp;
    return;
}
void display_linked_list(struct node *head)
{
    if (head==NULL)
    {
        printf("The list is empty");
        return;
    }
    struct node *current = head;
    while(current!=NULL)
    {
        printf("%d->", current->val);
        current = current->next;
    }
    printf("NULL\n");
}
void create_linked_list(struct node **head, int len_ll)
{
if (len_ll==0)
{
    *head = NULL;
    return;
}
*head= (struct node*)malloc(sizeof(struct node));
struct node *current = *head;
for(int i=0; i<len_ll; i++)
{
    printf("Enter the element: ");
    scanf("%d", &current->val);
    if (i!=len_ll-1)
    {
        current->next= (struct node *)malloc(sizeof(struct node));
        current = current->next;
    }
    else
        current->next = NULL;
}
}

int main()
{
    int len_ll, flag=0, choice, before_el, el;
    struct node *head=NULL;
    while(flag==0)
    {
        printf("\nEnter 1 to create a list,\n2 to display,\n3 to insert an element before another element,\n");
        printf("4 to insert an element after another element,\n5 to delete a particular element,\n6 to reverse the linked list,\n7 to sort list,\n");
        printf("8 to delete alternate node,\n9 to insert into a sorted order: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of elements in the linked list: ");
            scanf("%d", &len_ll);
            create_linked_list(&head,len_ll);
            break;
        case 2:
            printf("\nDisplaying the linked list: ");
            display_linked_list(head);
            break;
        case 3:
            printf("Enter the element before which you want to insert a node:");
            scanf("%d", &before_el);
            printf("Enter the element you want to insert into the list: ");
            scanf("%d",&el);
            insert_before_el(&head, before_el, el);
            display_linked_list(head);
            break;
        case 4:
            printf("Enter the element after which you want to insert a node: ");
            scanf("%d", &before_el);
            printf("Enter the element you want to insert into the list: ");
            scanf("%d", &el);
            insert_after_el(head, before_el, el);
            display_linked_list(head);
            break;
        case 5:
            printf("Enter the element you want to delete from the list: ");
            scanf("%d", &el);
            delete_el(&head, el);
            display_linked_list(head);
            break;
        case 6:
            printf("The reversed list is: ");
            reverse_linked_list(&head);
            display_linked_list(head);
            break;
        case 7:
            sort_linked_list(&head);
            break;
        case 8:
            delete_alternate_node(head);
            break;
        case 9:
            printf("ENter the element you want to insert into sorted order: ");
            scanf("%d", &el);
            insert_into_sorted_order(&head, el);
            break;


        }
    }


return 0;}
