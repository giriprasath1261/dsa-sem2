#include<stdio.h>
int a[1001];
int heap_size;
int parent(int i)
{
  return (i-1)/2;
}
int left(int i)
{
  return 2*i+1;
}
int right(int i)
{
  return 2*i+2;
}
void insert(int val)
{
  if(heap_size==1000)
    return;
  heap_size++;
  int i=heap_size-1;
  a[i]=val;
  while (i!=0&&a[parent(i)]>a[i]) {
    /* code */
    a[i]+=a[parent(i)];
    a[parent(i)]=a[i]-a[parent(i)];
    a[i]=a[i]-a[parent(i)];
    i=parent(i);
  }
}
int main(void)
{
  int n;
  int temp;
  scanf("%d",&n);
  int i=n;
  while(i--)
  {
    scanf("%d",&temp);
    insert(temp);
  }
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  printf("\n");
}
