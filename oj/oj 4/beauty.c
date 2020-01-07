
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int count=0;
int flag=0;
int converter(char c)
{
  int a = c - 97;
  return a;
}

struct node
{
    struct node *child[5];
    int end;
    int flag;
    int freq;
};

struct node *getnode()
{
    struct node* tempnode = (struct node *)malloc(sizeof(struct node));
    if (tempnode!=NULL)
    {
        int i;
        tempnode->end = 0;
        tempnode->flag= 0;
        tempnode->freq= 0;
        for (i = 0; i < 5; i++)
            tempnode->child[i] = NULL;
    }
    return tempnode;
}

void insert(struct node *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct node *movenode = root;
    for (level = 0; level < length; level++)
    {
        index = converter(key[level]);
        if (movenode->child[index]==NULL)
            movenode->child[index] = getnode();
        movenode = movenode->child[index];
    }
      movenode->freq+=1;

      movenode->end = 1;
}

void resetflag(struct node* root)
{
  if(root==NULL)
    return;
  root->flag=0;
  for(int i=0;i<5;i++)
    resetflag(root->child[i]);
}
// void inorder(struct node *root)
// {
//   long long int i;
// if(root->child!=NULL)
//   for(i=0;i<5;i++)
//   {
//     if(root->child[i]!=NULL)
//     {
//       inorder(root->child[i]);
//     }
//   }
//   printf("%lld",root->end);
// }

int search(struct node *root,const char *key,int level,int size,int flag)
{
  if(root==NULL||level>=size)
    return 0;
  if(level+1==size)
  {
    if(key[level]=='?')
    {
      if((root->end==1)&&(root->flag!=flag))
        {count+=root->freq;root->flag=flag;}
      for(int i=0;i<5;i++)
      {
        if((root->child[i]!=NULL)&&(root->child[i]->flag!=flag)&&(root->child[i]->end==1))
        {count+=root->child[i]->freq;root->child[i]->flag=flag;}
      }
      return 0;
    }
    else
    {
      int index=converter(key[level]);
      if((root->child[index]!=NULL)&&(root->child[index]->end==1)&&(root->child[index]->flag!=flag))
      {
        count+=root->child[index]->freq;
        root->child[index]->flag=flag;
        return 0;
      }
      else
        return 0;
    }
  }
  else
  {
    if(key[level]!='?')
    {
      int index=converter(key[level]);
      if(root->child[index]!=NULL)
      {search(root->child[index],key,level+1,size,flag);}
      else
        return 0;
    }
    else if(key[level]=='?')
    {
      for(int i=0;i<5;i++)
      {
        if(root->child[i]!=NULL)
          search(root->child[i],key,level+1,size,flag);
      }
      search(root,key,level+1,size,flag);
    }
  }

}

int main(void)
{
  struct node *root = getnode();
  int n;
  scanf("%d",&n);
  char a[5000];
  for(int i=0;i<n;i++)
  {
    scanf(" %s",a);
    insert(root,a);
  }
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    count =0;
    scanf(" %s",a);
    search(root,a,0,strlen(a),i+1);
    // resetflag(root);
    printf("%d\n",count);
  }
  return 0;
}
