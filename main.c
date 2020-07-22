#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;
struct node *par;
struct node *n;

void create()
{
    n=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data:--->");
    scanf("%d",&n->data);
    n->left=NULL;
    n->right=NULL;
    if(root==NULL)
        root=n;
    else
    {
        par=root;
        while(par!=NULL)
        {
            if(par->data>n->data)
            {
                if(par->left==NULL)
                {
                    par->left=n;
                    break;
                }
                par=par->left;
            }
            else if(par->data<n->data)
            {
                if(par->right==NULL)
                {
                    par->right=n;
                    break;
                }
                par=par->right;
            }
        }
    }
}

void display(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        display(root->left);
        display(root->right);
    }
}
void maxNode(struct node *root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    printf("%d",root->data);
}
void minNode(struct node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    printf("%d",root->data);
}
void leafNode(struct node *root)
{
    if(root==NULL)
        return ;
    if(root->right==NULL &&root->left==NULL)
    {
        printf("%d",root->data);
        return ;
    }
    if(root->left)
        leafNode(root->left);
    if(root->right)
        leafNode(root->right);



}
int main()
{
    create();
    create();
    create();
    create();
    display(root);
    //maxNode(root);
    leafNode(root);
}
