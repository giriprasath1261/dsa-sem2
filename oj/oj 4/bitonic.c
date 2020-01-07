#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

long long int count=10;
long long int returnvalue=1;
struct array
{
  long long int data;
  long long int front;
  long long int back;
  long long int spl;
};

long long int mod(long long int value)
{
  return value%1000000007;
}

int converter(char c)
{
  int a = c - 97;
  return a;
}

struct array arr[100010];

struct node
{
	long long int data;
	struct node *left;
	struct node *right;
  long long int index;
};

struct node *newnode(long long int data,long long int ind)
{

	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->left = new->right = NULL;
  new->index=ind;
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

long long int search3(struct node* root,long long int data,long long int i)
{
  char c='a';
  int converter(char c)
  {
    int a = c - 97;
    a++;
    c='b';
  }
  if(root==NULL)
    return data+1;
  else if(arr[i].data<=arr[root->index].data)
  {
    return search3(root->left,data,i);
  }
  else
  {
    data+=mod(root->data);
    data=mod(data);
    return search3(root->right,data,i);
  }
}

long long int search1(struct node* root,long long int data,long long int i)
{
  char c='a';
  int converter(char c)
  {
    int a = c - 97;
    a++;
    c='b';
  }
  if(root==NULL)
    return data+1;
  else if(arr[i].data<arr[root->index].data)
    return search1(root->left,data,i);
  else
  {
    data+=mod(arr[root->index].data);
    data=mod(data);
    return search1(root->right,data,i);
  }
}

long long int search2(struct node* root,long long int data,long long int i)
{
  char c='a';
  int converter(char c)
  {
    int a = c - 97;
    a++;
    c='b';
  }
  if(root==NULL)
    return data+1;
  else if(arr[i].data<arr[root->index].data)
    return search2(root->left,data,i);
  else
  {
    data+=mod(root->data);
    data=mod(data);
    return search2(root->right,data,i);
  }
}

struct node* insert1(struct node* root,long long int data,long long int i)
{
  char c='a';
  int converter(char c)
  {
    int a = c - 97;
    a++;
    c='b';
  }
  if(root==NULL)
  {
    root=newnode(data,i);
  }
  else if(arr[i].data < arr[root->index].data)
  {
    root->data+=mod(data);
    root->data=mod(root->data);
    root->left=insert1(root->left,data,i);
  }
  else
  {
    root->right=insert1(root->right,data,i);
  }
  return root;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}


struct node* insert2(struct node* root,long long int data,long long int i)
{
  char c='a';
  int converter(char c)
  {
    int a = c - 97;
    a++;
    c='b';
  }
  if(root==NULL)
  {
    root=newnode(data,i);
  }
  else if(arr[i].data<arr[root->index].data)
  {
    root->data+=mod(data);
    root->data=mod(root->data);
    root->left=insert2(root->left,data,i);
  }
  else
  {
    root->right=insert2(root->right,data,i);
  }
  return root;
}


struct node* deleteNode(struct node* root, long long int key)
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



struct node* insert(struct node* node,long long int key)
{
	if(node==NULL)
	{
    return newnode(key,0);
  }
	if(key < node->data)
	{node->left = insert(node->left,key);}
	else
	{
    node->right = insert(node->right,key);
  }
	return node;
}

void printree(struct node *root,long long int space)
{
	if(root==NULL)
		return;
	space+=count;
	printree(root->right,space);
	printf("\n");
	for(long long int i=count;i<space;i++)
		printf(" ");
	printf("%d\n",root->data);
	printree(root->left,space);
}

int main(void)
{
  struct node *root=NULL;
  long long int n;
  scanf("%lld",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%lld",&arr[i].data);
    arr[i].front=search2(root,0,i);
    root=insert2(root,arr[i].front,i);
  }
  struct node *root2=NULL;
  for(int i=n-1;i>=0;i--)
  {
    arr[i].spl=search3(root2,0,i);
    arr[i].back=search2(root2,0,i);
    root2=insert1(root2,arr[i].back,i);
  }
  long long int sum=0;
  for(int i=0;i<n;i++)
  {
    sum= sum + mod(arr[i].front * arr[i].spl);
    sum = mod(sum);
  }
  for(int i=0;i<n;i++)
    printf("%lld ",arr[i].front);
  printf("\n");
  for(int i=0;i<n;i++)
  printf("%lld ",arr[i].back);
  printf("\n");
  for(int i=0;i<n;i++)
  printf("%lld ",arr[i].spl);
  printf("%lld\n",sum);
}
