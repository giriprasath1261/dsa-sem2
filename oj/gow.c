#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
long long int flag=0;
long long int count =10;

struct node
{
	long long int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(long long int data)
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
		printf("\n%lld",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

struct node* insert(struct node* node,long long int key)
{

	if(node==NULL)
		return newnode(key);
	if(key < node->data)
		node->left = insert(node->left,key);
	else
		node->right = insert(node->right,key);
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
	printf("%lld\n",root->data);
	printree(root->left,space);
}


struct node * minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
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


long long int findmax(struct node* root)
{
	struct node* temp=root;
  while(temp->right!=NULL)
  {
    temp=temp->right;
  }
	long long int ret = temp->data;
	deleteNode(root,ret);
  return ret;
}

long long int findmaxsimple(struct node* root)
{
	struct node* temp=root;
  while(temp->right!=NULL)
  {
    temp=temp->right;
  }
	long long int ret = temp->data;
	// deleteNode(root,ret);
  return ret;
}


long long int addBT(struct node* root)
{
    if (root == NULL)
        return 0;
    return (root->data + addBT(root->left) + addBT(root->right));
}

struct node* search(struct node* root, long long int key)
{
    if (root == NULL )
      return root;
    if(root->data == key)
    { return root; flag=1;}
    if (root->data < key)
       return search(root->right, key);
    return search(root->left, key);
}

long long int main(void) {
  long long int n,t,k;
  struct node* root=NULL;
  struct node* root2=NULL;
  scanf("%lld%lld%lld",&n,&t,&k);
  long long int a[n];
	for(long long int i=0;i<n;i++)
		scanf("%lld",&a[i]);
  root=insert(root,a[0]);
  for(long long int i=1;i<t;i++)
  {
    insert(root,a[i]);
  }
	// printree(root,4);
  long long int temp;
  long long int value=findmax(root);
  root2=insert(root2,value);
  for(long long int i=1;i<k;i++)
  {
		temp=findmax(root);
    insert(root2,temp);
  }
	// printree(root2,4);
  long long int flag1=0;
  long long int sum=addBT(root2);
  long long int max=sum;
  for(long long int i=0;i<n-t;i++)
  {
		search(root2,a[i]);
		if(flag==1)
		{
			flag=0;
			deleteNode(root2,a[i]);
			if(a[t+i]>findmaxsimple(root))
			{
				insert(root2,a[t+i]);
				sum=sum-a[i]+a[t+i];
			}
			else
			{
				temp=findmax(root);
				insert(root2,temp);
				insert(root,a[t+i]);
				sum=sum-a[i]+temp;
			}
			if(sum>max)
			max=sum;
		}
    search(root,a[i]);
    if(flag==1)
    {
      flag=0;
      deleteNode(root,a[i]);
      insert(root,a[t+i]);
    }
  }
  printf("%lld\n",max);
  return 0;
}
