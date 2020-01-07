#include<stdio.h>
#include<stdlib.h>
struct Node
{
    long long int data;
    long long int rCount;
    long long int Sum ;
    struct Node* left;
    struct Node* right;
};

struct Node *createNode(long long int data)
{
	 struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->left = NULL;
    new->right = NULL;
    new->data = data;
    new->rCount = 0 ;
    new->Sum = 0;
    return new;
}

struct Node * insert(struct Node *root, long long int key)
{
//    printf("insert\n");
    if (root == NULL)
        return createNode(key);

    if (root->data > key)
    {
        root->left= insert(root->left , key);
    }
    else if (root->data < key )
    {
        root->rCount++;
        root->Sum += key;
        root->right= insert (root->right , key );
    }
    return root;
}


// struct Node * minValueNode(struct Node* node)
// {
//     struct Node* current = node;
//     while (current->left != NULL)
//         current = current->left;
//     return current;
// }
//
// struct Node* deleteNode(struct Node* root, long long int key)
// {
//     if (root == NULL) return root;
//     if (key < root->data)
//         root->left = deleteNode(root->left, key);
//     else if (key > root->data)
//         root->right = deleteNode(root->right, key);
//     else
//     {
//         if (root->left == NULL)
//         {
//             struct Node *temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL)
//         {
//             struct Node *temp = root->left;
//             free(root);
//             return temp;
//         }
//         struct Node* temp = minValueNode(root->right);
//         root->data = temp->data;
//         root->right = deleteNode(root->right, temp->data);
//     }
//     return root;
// }

struct Node* minValue(struct Node* node) {
  struct Node* current = node;

  while (current->left != NULL) {
    current = current->left;
  }
  return(current);
}

struct Node* Delete(struct Node *root, long long int data) {
  printf("Delete\n");
  if (root == NULL) {
     return NULL;
  }
  if (data > root->data) {
      root->left = Delete(root->left, data);
  } else if (data > root->data) {
      root->right = Delete(root->right, data);
  } else {

     if (root->left == NULL) {
        struct Node* temp=root->right;
        free(root);
        return temp;
     }
     else if (root->right == NULL) {
        struct Node *temp = root->left;
        free(root);
        return temp;
     }
     struct Node* temp = minValue(root->right);
     root->data=temp->data;
     root->right=Delete(root->right,temp->data);
  }
  return root;
}

long long int sum;
void klargestElementSumRec(struct Node *root, long long int k)
{
    if (root == NULL)
        return ;
    if ((root->rCount + 1) == k)
    {
        sum += root->data + root->Sum ;
        return ;
    }
    else if (k > root->rCount)
    {
        sum += root->data + root->Sum;
        k = k -( root->rCount + 1);
        klargestElementSumRec(root->left , k);
    }
    else
        klargestElementSumRec(root->right , k);
}

int klargestElementSum(struct Node *root, long long int k)
{
    sum = 0;
    klargestElementSumRec(root, k);
    return sum;
}

void print(struct Node* root)
{
    if(root->left)
      print(root->left);
    printf("%lld\n", root->data);
    if(root->right)
      print(root->right);
}

int main(void)
{
    long long int n,t,k,sum=0,max=0;
    struct Node* root=NULL;
    scanf("%lld%lld%lld",&n,&t,&k);
    long long int a[n];
    for(long long int i=0;i<n;i++)
      scanf("%lld",&a[i]);
    root=insert(root,a[0]);
    for(long long int i=1;i<t;i++)
    {
      insert(root,a[i]);
    }
    print(root);
    sum=max=klargestElementSum(root,k);
    for(long long int i=t;i<n;i++)
    {
      Delete(root,a[i-t]);
      insert(root,a[i]);
      sum=klargestElementSum(root,k);
      print(root);
      printf("%lld\n", sum);
      if(sum>max)
        max=sum;
    }
    printf("%lld\n",max);
    return 0;
}
