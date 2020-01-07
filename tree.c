#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

int count=10;
int max=0;
int ldep=0;
int rdep=0;
int depth=0;

struct node
{
        int data;
        struct node *left;
        struct node *right;
	int dep;
	int ans;
};

struct node *newnode(int data)
{

        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->data=data;
        new->left = new->right = NULL;
        return new;
}

void preorder(struct node *temp)
{
        if(temp!=NULL)
        {
                printf("\n%d",temp->data);
                preorder(temp->left);
                preorder(temp->right);
        }
}

struct node* insert(struct node* node,int key)
{

        if(node==NULL)
	{return newnode(key);}
        if(key < node->data)
	{node->left = insert(node->left,key);}
        else
	{node->right = insert(node->right,key);}
        return node;
}

int finddepth(struct node *node)
{
	if(node == NULL)
		return 0;
	else
	{
		ldep=finddepth(node->left);
		rdep=finddepth(node->right);
	}
	if(ldep>rdep)
		return ldep+1;
	else
		return rdep+1;
}

void printree(struct node *root,int space)
{
        if(root==NULL)
                return;
        space+=count;
        printree(root->right,space);
        printf("\n");
        for(int i=count;i<space;i++)
                printf(" ");
        printf("%d\n",root->data);
        printree(root->left,space);
}

void print2(struct node *node,int depth)
{
	if(node!=NULL)
	{
		print2(node->left,depth+1);
		printf("%d\t",finddepth(node)+depth);
		print2(node->right,depth+1);
	}
}

int main()
{
        struct node *root=NULL;
	int size;
	scanf("%d",&size);
        int data[size];
	for(int i=0;i<size;i++)
		scanf("%d",&data[i]);
        root=insert(root,data[0]);
        for(int i=1;i<size;i++)
        {
                insert(root,data[i]);
        }
        //printf("Printing the tree \n\n\n");
        //preorder(root);
        //printree(root,0);
	print2(root,0);
	//int some=finddepth(root->left);
	printf("\n");
        return 0;
}

