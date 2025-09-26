#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
int val;
struct node *next;
};

int isEmpty(struct node **front)
{
    return(*front==NULL);
}


void enqueue(struct node **head, struct node **front, struct node **rear, int val)
{
    if(isEmpty(front))
    {
        *front=*head;
    }
    (*rear)->next=(struct node*)malloc(sizeof(struct node));
    (*rear)= (*rear)->next;
    (*rear)->val = val;

}

void dequeue(struct node **head, struct node **front, struct node **rear)
{
    if(isEmpty(front))
    {
        printf("The queue is empty: ");
        return ;
    }
    printf("Value dequeued is: %d", (*front)->val);
    if(*front==*rear)
    {
        *front = NULL;
        *rear= NULL;
    }
    else{
        *front = (*front)->next;

    }


}
int main()
{
    int flag = 1, choice, val;
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *front = NULL, *rear = NULL;
    while(flag==1)
    {
        printf("Enter 1 to enqueue, 2 to dequeue, and 3 to display the queue created: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            enqueue(&head, &front, &rear, val);
            break;
        case 2:
            dequeue(&head, &front, &rear);
            break;

        }
        printf("Do you want to continue?0/1: ");
        scanf("%d", &flag);
    }

    return 0;
}
