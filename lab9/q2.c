#include<stdio.h>
#include<stdlib.h>

struct BTree{
int val;
struct BTree *left;
struct BTree *right;
}*root=NULL;

void add_node(struct BTree **parent, struct BTree **current)
{
int choice_left, choice_right;
printf("Do you want to add a link to the left? :0/1");
scanf("%d", &choice_left);
printf("Do you want to add a link to the right? : 0/1");
scanf("%d", &choice_right);
if(choice_left==1)
{
(*parent)->left = (struct BTree*)malloc(sizeof(struct BTree));
printf("Enter the value: ");
scanf("%d",&(*parent)->left->val);
*current= (*parent)->left;
}
if(choice_right==1)
{
(*parent)->right = (struct BTree*)malloc(sizeof(struct BTree));
printf("Enter the value: ");
scanf("%d",&(*parent)->right->val);
*current= (*parent)->right;
}
}
void create_BTree(struct BTree *node, struct BTree **left_node, struct BTree **right_node, int val)
{
    if(*left_node==NULL && *right_node==NULL)
    {
        return;
    }
    else if(*left_node==NULL)
    {
        (*right_node)->val=val;
        printf("Enter the value of the right node: ");
        create_BTree(node, &right_node, NULL);

    }
    else
    {

        (*left_node)->val = val;
        printf("ENter the value of the left node: ");
        create_BTree(node, &left_node, NULL);
    }
}


void print_BTree(struct BTree *node)
{
    if(node == NULL)
    {
        return;
    }
    printf("%d\n", node->val);
    return print_BTree(node->left);
    return print_BTree(node->right);

}
int main()
{
    create_BTree(root);
    printf("Do you really know what you are doing or are you bluffing?");
    print_BTree(root);
return 0;
}
