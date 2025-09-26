#include<stdio.h>
#include<string.h>
#define MAX_SIZE 10
struct printer{
int doc_id;
char name[20];
};
struct printer jobs[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty()
{
    return(front==-1);
}
int isFull()
{
    return(rear == MAX_SIZE-1);

}
void enqueue(int ID, char name[20])
{
    if(isFull())
    {
        printf("The queue is full. ");
        return;
    }
    else if(isEmpty())
        front=0;
    jobs[++rear].doc_id = ID;
    strcpy(jobs[rear].name,name);
}
void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is already empty. ");
        return;
    }
    printf("Popped ID: %d, Popped Doc name: %s",jobs[front].doc_id, jobs[front].name);
    if(front==rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front++;

}

void display_jobs()
{
    if(!isEmpty()){
    printf("\nPrinter Jobs: \n");
    for(int i = front; i<=rear; i++)
    {
        printf("DocID: %d, name: %s\n", jobs[i].doc_id, jobs[i].name);
    }}
    else
        printf("\nNo jobs left. \n");
}
int main()
{
    int flag=1, choice;
    int ID;
    char name[20];
    while(flag==1)
    {
        printf("Enter 1 to enqueue, 2 to dequeue and 3 to display the jobs: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the job ID: ");
            scanf("%d", &ID);
            printf("Enter the name: ");
            scanf("%s", name);
            enqueue(ID, name);
            display_jobs();
            break;
        case 2:
            dequeue();
            display_jobs();
            break;
        case 3:
            display_jobs();
            break;
        }

        printf("\nDo you want to continue?0/1: ");
        scanf("%d", &flag);
    }

    return 0;
}
