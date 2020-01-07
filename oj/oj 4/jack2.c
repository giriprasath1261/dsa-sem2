#include<stdio.h>
#include<stdlib.h>

long long int Queue[50050];
int l = -1;
int r = -1;

int Empty()
{
  if(l == -1)
  return 1;
  else
  return 0;
}

int leqr()
{
  if(l == r)
  return 1;
  else
  return 0;
}

void fadd( long long int data )
{
  if(Empty())
	{l = 0;r = 0;}
	else
	   Queue[++r] = data;
}

void radd( long long int data )
{
	if(Empty())
	{l = 0;r = 0;}
	else if(l== 0)
		l=50050-1;
	else
	   Queue[--l] = data ;
}

void rdel()
{
	if(leqr())
	{l = -1;r=-1;}
	else if(l == 50050-1)
		l = 0;
	else
		l++;
}
void fdel()
{
	if(leqr())
	{l = -1;r=-1;}
	else if(r == 0)
		r=50050-1;
	else
		r--;
}

void insnode(long long input)
{
	while((l!=-1)&&(Queue[l]>input))
		rdel();
	radd(input);
}

void delnode(long long input)
{
	if((l!=-1)&&(Queue[r]==input))
		fdel();
}

long long int mintime(long long int n,long long int k,long long int ARR[])
{
	long long ARR2[n];
	ARR2[0] = ARR[0];
	insnode(ARR2[0]);
	for(int i=1; i<k; i++)
	{
		ARR2[i] = ARR[0] + ARR[i];
		insnode(ARR2[i]);
	}
	for(int i=k; i<n; i++)
	{
		ARR2[i] = ARR[i] + Queue[r];
		delnode(ARR2[i-k]);
		insnode(ARR2[i]);
	}
  // for(int i=0;i<n;i++)
  // {
    // printf("%lld ",ARR[i]);
  // }
  if(k>=n)
  {
    // printf("%lld\n",ARR[0]+ARR[n-1]+n-1);
    return ARR[0]+ARR[n-1]+n-1;
  }
  else
  {
    // printf("%lld\n",ARR2[n-1]+n-1);
    return ARR2[n-1]+n-1;
  }
}


int main(void)
{
  long long int n,t;
  scanf("%lld %lld",&n,&t);
  long long int cost_size=n-1,time_size=n-2;
  long long int cost[n+5],time[n+5];
  cost[0]=0;
  for(int i=1;i<n;i++)
      scanf("%lld",&cost[i]);
  time[0]=0;time[n-1]=0;
  for(int i=1;i<n-1;i++)
      scanf("%lld",&time[i]);
  long long int start=1;
  long long int end=n-1;
  long long int mid;
  long long int new;
  while(start<=end)
  {
    mid=(start+end)/2;
    if(mintime(n,mid,time)<=t)
    {
      new=mid;
      end=mid-1;
    }
    else
    {
      start=mid+1;
    }
    // printf("%lld ",mintime(n,mid,time));
  }
  // printf("\n");
  long long int min=cost[new];
  for(int i=new+1;i<n;i++)
  {
    if(cost[i]<min)
      min=cost[i];
  }
  printf("%lld\n",min);
  return 0;
}
