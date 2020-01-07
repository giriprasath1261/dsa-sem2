#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

long long int flag=0;
long long int count =0;

struct node
{
	long long int data;
  long long int lsum;
	struct node *left;
	struct node *right;
};

struct node *newnode(long long int data)
{

	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data=data;
  new->lsum=0;
	new->left = new->right = NULL;
	return new;
}

void inorder(struct node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
    printf("%lld ",temp->data);
		inorder(temp->right);
	}
}

struct node* insert(struct node* node,long long int key)
{

	if(node==NULL)
		return newnode(key);
	if(key < node->data)
  {
    node->lsum+=key;
		node->left = insert(node->left,key);
  }
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
    {
			root->left = deleteNode(root->left, key);
			root->lsum-=key;
		}
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

long long int taxcalc(struct node* root,long long int val,long long int sum,char ch)
{
	if(val==0)
		return 1e9;
  // if(root==NULL)
    // return root;
  long long int temp_sum=root->lsum;
  long long int check=(temp_sum)/10 + (sum-temp_sum)/2;
	long long int ans=0;
  while(root!=NULL)
  {
    if(check==val)
    {
      return root->data;
    }
    else if(check<val)
    {
      if(root->left==NULL)
        break;
      temp_sum=(temp_sum)-(root->lsum)+(root->left->lsum);
      check=(temp_sum)/10 + (sum-temp_sum)/2;
      root=root->left;
    }
    else
    {
			ans=root->data;
      if(root->right==NULL)
        break;
      temp_sum=temp_sum+(root->data)+(root->right->lsum);
      check=(temp_sum)/10 + (sum-temp_sum)/2;
      root= root->right;
    }
		// printf("%lld %lld\n",temp_sum,check);
  }
  if(check>val)
  {
    if((sum/10)>=val||count==0)
      return 1000000000;
    return root->data;
  }
  if(check<val)
  {
		if(ans==0)
    	return -1;
		else
			return ans;
  }
}
void ff(struct node *root,long long int sum)
{
	sum+=root->lsum;
	if(root->left!=NULL)
	{
		sum-=root->lsum;
		ff(root->left,sum);
	}
	printf("%lld ",sum+root->data);
	if(root->right!=NULL)
	{
		ff(root->right,sum+root->data);
	}
}
int main(void)
{
   long long int t,u,sum=0;
   scanf("%lld",&t);
   getchar();
   struct node* root=NULL;
   for(u=0;u<t;u++)
   {
     char ch='R';
     long long int num;
     while(ch!='A')
     {
       scanf("%c %lld",&ch,&num);
       getchar();
       if(ch=='H')
       {
         if(count==0)
         {
           root=insert(root,num);count++;sum+=num;
					 // printree(root,2);
         }
         else
         {
           insert(root,num);count++;sum+=num;
					 // inorder(root);
					 // printree(root,2);
         }
				 // inorder(root);
				 // printf("\n");
				 // ff(root,0);
				 // printf("\n");
       }
       else if(ch=='F')
       {
         deleteNode(root,num);count--;sum-=num;
				 // inorder(root);
				 // printf("\n");
				 // ff(root,0);
				 // printf("\n");
			 }
       else
       {
          long long int temp=taxcalc(root,num,sum,ch);
					if(temp==-1)
						printf("Alert!\n");
					else
						printf("%lld\n",temp);
       }
     }
		 // printree(root,3);
   }
   return 0;
}
