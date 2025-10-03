#include<stdio.h>
#include<stdlib.h>

struct BTree{
int val;
struct BTree *left;
struct BTree *right;
}*head=NULL;

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
void create_BTree(struct BTree *node, struct BTree **left_node, struct BTree **right_node)
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

void postorder(struct BTree *head)
{
    for(struct node *current = head; current; current = current->next)
    {
        if(current==NULL)
            break
        printf("%d", current->val);
    }
}
void inorder(struct BTree **head)
{
    for(current = *head; current; current = current->left)
    {
        printf("%d", current->val);
    }
    for(current = *head; current; current = current->right)
    {
        printf("%d", current->val);
    }
}
void preorder(struct BTree **head)
{
    for(current = *head; current; current =current->right)
    {
        printf("%d", current->val);
    }
    for(current = *head; current; current = current->left)
    {
        printf("%d", current->val);
    }
}

void find_parent(struct BTree *head, int val)
{

    for(current = *head; current; current= current->right)
    {
        if(current->right->val==val)
        {
            printf("Parent is: %d", current->val);
            return;
        }
    }
    for(current = *head; current; current= current->left)
    {
        if(current->left->val==val)
        {
            printf("Parent is: %d", current->val);
            return;
        }
    }
    printf("Element not found in the tree");
    return;
}

void find_depth(struct BTree *head, int depth)
{
    for(struct BTree *current = head; current; current=current->right)
    {
        find_depth(head, depth);
    }
}


int main()
{
    head = (struct BTree *)malloc(sizeof(struct BTree));
    printf("Enter the value of the head: ");
    scanf("%d", &head->val);
    struct BTree *current = (struct BTree *)malloc(sizeof(struct BTree));
    *current = head;
return 0;
}
