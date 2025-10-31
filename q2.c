#include<stdio.h>
#include<stdlib.h>

typedef struct graph{
int val;
struct graph *next;
}*Node;

Node adj_list[20];
int visited[200];
void init_adj_list(int n)
{
    for(int i=0; i<n; i++)
    {
        adj_list[i]=NULL;
    }
}

void add_edge(int src, int dest, int dir)
{
    Node destNode=(Node)malloc(sizeof(struct graph));
    destNode->val=dest;
    destNode->next=adj_list[src];
    adj_list[src]=destNode;

    if(!dir)
    {
        Node srcNode=(Node)malloc(sizeof(struct graph));
        srcNode->val=src;
        srcNode->next = adj_list[dest];
        adj_list[dest]= srcNode;
    }
}

void display_adj_list(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d: ", i);
        Node curr=adj_list[i];
        while(curr!=NULL)
        {
            printf("%d, ", curr->val);
            curr=curr->next;
        }
        printf("\n");
    }
}
void init_visited(int n)
{
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
    }
}
Node dfs(Node root)
{
    if(root==NULL)
        return NULL;
    printf("%d ", root->data);
    visited(root->data)=1;
    Node curr=adj_list[root->data];
    while(curr!=NULL)
    {
        if(adj_list[curr->next->data]==0)
        {
            dfs(curr->next);
        }
        curr=curr->next;
    }
}
Node q[200];
int front=rear=-1;

void bfs(Node root)
{
    if(root==NULL)
        return NULL;
    visited(root->data)=1;
    Node curr=adj_list[root->data];
    while(curr!=NULL)
    {
        if(adj_list[curr->next->data]==0)
        {
            printf("%d", curr->data);

        }
    }
}
int main()
{
    int n, src, dest, dir;
    printf("Do you want to create a directed or undirected graph? 0/1: ");
    scanf("%d", &dir);
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_adj_list(n);
    display_adj_list(n);
    int flag =1;
    while(flag==1)
    {
        printf("Enter the edge: ");
        printf("Enter the source: ");
        scanf("%d", &src);
        printf("Enter the destination: ");
        scanf("%d", &dest);
        add_edge(src, dest, dir);
        printf("Do you want to continue?: 0/1: ");
        scanf("%d", &flag);
    }
    display_adj_list(n);
    Node root=dfs()
return  0;
}
