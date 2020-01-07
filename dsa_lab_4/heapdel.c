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
    a[i]+=a[parent(i)];
    a[parent(i)]=a[i]-a[parent(i)];
    a[i]=a[i]-a[parent(i)];
    i=parent(i);
  }
}
void minheapify(int i)
{
  int l=left(i);
  int r=right(i);
  int small=i;
  if (l<heap_size&&a[small]>a[l])
    small=l;
  if(r<heap_size&&a[small]>a[r])
    small=r;
  if (small!=i) {
    a[small]+=a[i];
    a[i]=a[small]-a[i];
    a[small]=a[small]-a[i];
    minheapify(small);
  }
}
void delete(int i)
{
  heap_size--;
  a[heap_size]+=a[i];
  a[i]=a[heap_size]-a[i];
  a[heap_size]=a[heap_size]-a[i];
  minheapify(i);
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
  scanf("%d",&i);
  delete(i);
  for (i = 0;i < heap_size;i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
}
