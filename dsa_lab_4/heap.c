#include<stdio.h>
#include<stdlib.h>

int arr[100];

int parent(int index)
{
  return(index-1)/2;
}


int insert(int value,int index)
{
  arr[index]=value;
  while((value<arr[parent(index)])&&((parent(index)>=0)))
  {
    int temp=arr[index];
    arr[index]=arr[parent(index)];
    arr[parent(index)]=temp;
    index=parent(index);
  }
}

int main()
{
    int size;
  	scanf("%d",&size);
          int data[size];
  	for(int i=0;i<size;i++)
  		scanf("%d",&data[i]);
    insert(data[0],0);
    for(int i=1;i<size;i++)
    {
      insert(data[i],i);
    }
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
