#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

int count=10;

struct node
{
	int data;
	struct node *left;
	struct node *right;
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


struct node * minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}


struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



struct node* insert(struct node* node,int key)
{

	if(node==NULL)
		return newnode(key);
	if(key < node->data)
		node->left = insert(node->left,key);
	else
		node->right = insert(node->right,key);
	return node;
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

int main()
{
	struct node *root=NULL;
	int size;
	printf("enter size\n");
	scanf("%d",&size);
	int data[size];
	scanf("%d",&data[0]);
	root=insert(root,data[0]);
	for(int i=1;i<size;i++)
	{
		printf("Enter next value : ");
		scanf("%d",&data[i]);
		// if(data == -1)
			// break;
		insert(root,data[i]);
	}
	// printf("Printing the tree \n\n\n");
	//preorder(root);
	printree(root,1);
	int value;
	printf("Enter value to delete\n");
	scanf("%d",&value);
	deleteNode(root,value);
	printree(root,1);
	printf("\n");
	return 0;
}
