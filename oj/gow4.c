+#include<stdio.h>
#include<stdlib.h>

long long int h1size=0,h2size=0;

long long int parent(long long int index)
{
  return(index-1)/2;
}
long long int left(long long int i)
{
  return 2*i+1;
}
long long int right(long long int i)
{
  return 2*i+2;
}

struct node{
  long long int data;
  long long int h1;
  long long int h2;
};

struct node a[100010];

struct node2{
  long long int data;
  long long int index;
};

void insertmin(struct node2 arr[],long long int index)
{
  h1size++;
  long long int i=h1size-1;
  arr[i].data=a[index].data;
  a[index].h1=i;
  a[index].h2=-1;
  arr[i].index=index;
  while((a[index].data<arr[parent(i)].data)&&(parent(i)>=0))
  {
    long long int itemp=a[arr[i].index].h1;
    a[arr[i].index].h1=a[arr[parent(i)].index].h1;
    a[arr[parent(i)].index].h1=itemp;

    long long int temp=arr[i].data;
    arr[i].data=arr[parent(i)].data;
    arr[parent(i)].data=temp;

    long long int tempi=arr[i].index;
    arr[i].index=arr[parent(i)].index;
    arr[parent(i)].index=tempi;
    i=parent(i);
  }
}


void insertmax(struct node2 arr[],long long index)
{
  h2size++;
  long long int i=h2size-1;
  arr[i].data=a[index].data;
  a[index].h2=i;
  a[index].h1=-1;
  arr[i].index=index;
  while((a[index].data>arr[parent(i)].data)&&(parent(i)>=0))
  {
    long long int itemp=a[arr[i].index].h2;
    a[arr[i].index].h2=a[arr[parent(i)].index].h2;
    a[arr[parent(i)].index].h2=itemp;

    long long int temp=arr[i].data;
    arr[i].data=arr[parent(i)].data;
    arr[parent(i)].data=temp;

    long long int tempi=arr[i].index;
    arr[i].index=arr[parent(i)].index;
    arr[parent(i)].index=tempi;

    i=parent(i);
  }
}


void merge(long long int arr[],long long int l,long long int m,long long int r)
{
  long long int n2 =  r - m;
  long long int n1 = m - l + 1;
  long long int Larr[n1], Rarr[n2];
  long long int a, b, c;
  c = l;
  for (a = 0; a < n1; a++)
  Larr[a] = arr[l + a];
  for (b = 0; b < n2; b++)
  Rarr[b] = arr[m + 1 + b];
  b = 0;
  a = 0;

  while (a < n1 && b < n2)
  {
    if (Larr[a] <= Rarr[b])
      arr[c++] = Larr[a++];
    else
      arr[c++] = Rarr[b++];
  }
  while (a < n1)
    arr[c++] = Larr[a++];
  while (b < n2)
    arr[c++] = Rarr[b++];
}

void minheapify(struct node2 arr[],long long int i)
{
  long long int l=left(i);
  long long int r=right(i);
  long long int small=i;
  if (l<h1size&&arr[small].data>arr[l].data)
    small=l;
  if(r<h1size&&arr[small].data>arr[r].data)
    small=r;
  if (small!=i) {
    long long int itemp=a[arr[i].index].h1;
    a[arr[i].index].h1=a[arr[small].index].h1;
    a[arr[small].index].h1=itemp;

    long long int temp=arr[i].data;
    arr[i].data=arr[small].data;
    arr[small].data=temp;

    long long int tempi=arr[i].index;
    arr[i].index=arr[small].index;
    arr[small].index=tempi;

    minheapify(arr,small);
  }
}



void maxheapify(struct node2 arr[],long long int i)
{
  long long int r=right(i);
  long long int l=left(i);
  long long int small=i;
  if (l<h2size&&arr[small].data<arr[l].data)
    small=l;
  if(r<h2size&&arr[small].data<arr[r].data)
    small=r;
  if (small!=i) {
    long long int itemp=a[arr[i].index].h2;
    a[arr[i].index].h2=a[arr[small].index].h2;
    a[arr[small].index].h2=itemp;

    long long int temp=arr[i].data;
    arr[i].data=arr[small].data;
    arr[small].data=temp;

    long long int tempi=arr[i].index;
    arr[i].index=arr[small].index;
    arr[small].index=tempi;

    minheapify(arr,small);
  }
}


void deletemin(struct node2 arr[],long long int i)
{
  h1size--;
  // long long int temp=arr[h1size];
  // long long int itemp=a[h1size].h1;
  // arr[h1size]=arr[i];
  // a[h1size].h1=a[i].h1;
  // arr[i]=temp;
  // a[i].h1=itemp;
  // a[h1size].h1=-1;

  long long int itemp=a[arr[h1size].index].h1;
  a[arr[h1size].index].h1=a[arr[i].index].h1;
  a[arr[i].index].h1=itemp;
  a[arr[i].index].h1=-1;

  long long int temp=arr[h1size].data;
  arr[h1size].data=arr[i].data;
  arr[i].data=temp;

  long long int tempi=arr[h1size].index;
  arr[h1size].index=arr[i].index;
  arr[i].index=tempi;

  minheapify(arr,i);
}


void deletemax(struct node2 arr[],long long int i)
{
  h2size--;

  long long int itemp=a[arr[h2size].index].h2;
  a[arr[h2size].index].h2=a[arr[i].index].h2;
  a[arr[i].index].h2=itemp;
  a[arr[i].index].h2=-1;

  arr[h2size].data=arr[i].data;
  long long int temp=arr[h2size].data;
  arr[i].data=temp;

  long long int tempi=arr[h2size].index;
  arr[h2size].index=arr[i].index;
  arr[i].index=tempi;

  maxheapify(arr,i);
}

void mergeSort(long long int arr[], long long int left, long long int right)
{
    if (left+arr[0] < right+arr[0])
    {
        long long int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

// void function()
// {
//   printf("%lld %lld %lld\n",max,maxstart,maxend);
//   for(long long int i=k;i<t;i++)
//   {
//     if(a[i].data>arrmin[0].data)
//     {
//       insertmax(arrmax,arrmin[0].index);
//       sum=sum-arrmin[0].data+a[i].data;
//       deletemin(arrmin,0);
//       insertmin(arrmin,i);
//       if(sum>max)
//         max=sum;
//     }
//     else
//     {
//       insertmax(arrmax,i);
//     }
//   }
//   for(int i=0;i<k;i++)
//     printf("%lld ",arrmin[i].data);
//     printf("\n");
//   for(int i=0;i<t-k;i++)
//     printf("%lld \n",arrmax[i].data);
//   for(int i=0;i<t;i++)
//   {
//     printf("%lld ",a[i].h1);
//     printf("%lld \n",a[i].h2);
//   }
//   for(long long int i=t;i<n;i++)
//   {
//     if(a[i-t].h1==-1)
//     {
//       deletemax(arrmax,a[i-t].h2);
//       if(arrmax[0].data>a[i].data)
//       {
//         insertmax(arrmax,i);
//       }
//       else
//       {
//         if(arrmin[0].data>a[i].data)
//         {
//           insertmax(arrmax,i);
//         }
//         else
//         {
//           insertmax(arrmax,arrmin[0].index);
//           sum=sum-arrmin[0].data+a[i].data;
//           deletemin(arrmin,0);
//           insertmin(arrmin,i);
//           if(sum>max)
//             max=sum;
//         }
//
//       }
//     }
//     else
//     {
//       if(h2size!=0)
//       {
//         int dump=a[i-t].data;
//         deletemin(arrmin,a[i-t].h1);
//         if(arrmax[0].data>a[i].data)
//         {
//           insertmin(arrmin,arrmax[0].index);
//           sum=sum-dump+arrmax[0].data;
//           deletemax(arrmax,0);
//           insertmax(arrmax,i);
//           if(sum>max)
//           max=sum;
//         }
//         else
//         {
//           insertmin(arrmin,i);
//           sum=sum-dump+a[i].data;
//           if(sum>max)
//             max=sum;
//         }
//       }
//       else
//       {
//         int dump=a[i-t].data;
//         deletemin(arrmin,a[i-t].h1);
//         insertmin(arrmin,i);
//         sum=sum-dump+a[i].data;
//         if(sum>max)
//           max=sum;
//       }
//     }
//   }
// }

int main(void)
{
  long long int n,t,k,sum=0,max=0;
  scanf("%lld%lld%lld",&n,&t,&k);
  long long int a[n],arr[t];
  for(long long int i=0;i<n;i++)
    scanf("%lld",&a[i]);
  long long int start=0,maxstart=0;
  long long int end=t,maxend=t-1;
  while(end<=n)
  {
    long long int i=start;
    sum=0;
    while(i<end)
    {
      sum+=a[i];
      i++;
    }
    if(sum>max)
    {
      max=sum;
      maxend=end-1;
      maxstart=start;
    }
    start++;end++;
  }

  for(long long int i=0;i<t;i++)
  {
    arr[i]=a[maxstart+i];
  }
  mergeSort(arr,0,t-1);
  long long int finsum=0;
  for(long long int i=t-k;i<t;i++)
  {
    finsum+=arr[i];
  }
  printf("%lld\n",finsum);
}
