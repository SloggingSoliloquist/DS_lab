#include<stdio.h>
#include<stdlib.h>

typedef struct circular_ll{
int val;
struct circular_ll *next;
}circular_ll;

void del_beg_or_end(circular_ll **head, circular_ll **tail, int beg_or_end)
{
    if(*head==NULL)
    {
        return;
    }
    else if (*head==*tail)
    {
        *head = NULL;
        *tail = NULL;
        return;
    }
    if(beg_or_end==0)
    {
        circular_ll *del_node = *head;
        (*tail)->next=(*tail)->next->next;
        *head = (*tail)->next;
        free(del_node);
        return;
    }
    else if(beg_or_end==1)
    {
        circular_ll *current = *head;
        while(current->next->next!=*head)
        {
            current= current->next;
        }
            current->next = current->next->next;
            circular_ll *temp = *tail;
            *tail = current;
            free(temp);
            return;

    }
}
void insert_end(circular_ll **head, circular_ll **tail, int el)
{
    if(*head==NULL)
    {
        circular_ll * new_node = (circular_ll *)malloc(sizeof(circular_ll));
        new_node->val = el;
        *head= new_node;
        *tail=new_node;
        (*tail)->next = *head;
        return;
    }
    circular_ll * new_node = (circular_ll *)malloc(sizeof(circular_ll));
    new_node->val = el;
    new_node->next= *head;
    (*tail)->next = new_node;
}
void create_cll(circular_ll **head, circular_ll**tail, int len)
{
    if(len==0)
    {
        *head= NULL;
        *tail = NULL;
        return;
    }
    *head= (circular_ll*)malloc(sizeof(circular_ll));
    circular_ll *current = *head;
    for (int i = 0; i<len; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &current->val);
        if (i!=len-1)
        {
            current->next = (circular_ll *)malloc(sizeof(circular_ll));
            current = current->next;
        }
        else{
            current->next = *head;
            *tail=current;
            return;
        }
    }
}

void display_cll(circular_ll **head)
{
    if(*head==NULL)
    {
        printf("List is empty");
        return;
    }
    circular_ll *current = *head;
    do{
        printf("%d->", current->val);
        current=current->next;
    }
    while(current!=*head);
    printf("%d(First)", current->val);
}
int main()
{
    int len,el,beg_or_end, choice, flag = 0;
    circular_ll *head, *tail;
    while(flag==0)
    {
        printf("\nEnter 1 to create a circular linked list,\n2to display it,\n3 to insert at the end,\n4 to delete from the beginning or end: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the length of the linked list: ");
            scanf("%d", &len);
            create_cll(&head, &tail, len);
            display_cll(&head);
            break;
        case 2:
            printf("The list is: ");
            display_cll(&head);
            break;
        case 3:
            printf("Enter the element you want to insert at the end: ");
            scanf("%d",&el);
            insert_end(&head, &tail, el);
            display_cll(&head);
            break;
        case 4:
            printf("Do you want to delete from the beginning or the end? 0/1:");
            scanf("%d", &beg_or_end);
            if(beg_or_end>1)
            {
                printf("Invalid option\n");
                break;
            }
            else{
            del_beg_or_end(&head, &tail, beg_or_end);
            display_cll(&head);
            break;}
        }
    }

return 0;
}
