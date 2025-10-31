#include<stdio.h>
#include<stdlib.h>

int a[200][200];

void init_adj_matrix(int size)
{
    for(int i=0;i<size; i++)
    {

        for(int j = 0; j<size; j++)
        {
            a[i][j]=0;
        }
    }
}

void add_edge(int src, int dest, int dir)
{
    a[src][dest]=1;
    if(dir!=1)
    {
        a[dest][src]=1;
    }
}

void print_adj_matrix(int size)
{

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int size, edges, dir, src, dest;
    printf("Do you want to create a directed or undirected graph? 1/0: ");
    scanf("%d", &dir);
    int flag=1;
    printf("Enter the number of vertices: ");
    scanf("%d", &size);
    init_adj_matrix(size);
    while(flag==1)
    {
        printf("Enter the edge: \n");
        printf("Enter the source: ");
        scanf("%d", &src);
        printf("Enter the destination: ");
        scanf("%d", &dest);
        add_edge(src, dest, dir);
        printf("Do you want to add more edges? 0/1: ");
        scanf("%d", &flag);
    }
    printf("\nThe adjacency matrix created: \n");
    print_adj_matrix(size);
    return 0;
}
