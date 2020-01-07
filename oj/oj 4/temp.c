#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

long long int max=INT_MIN,sum=0;
long long Q[1000010];
long long int l = -1;
long long int r = -1;

bool Empty()
{
	if(l == -1)
	return true;
	else
	return false;
}

bool ler()
{
	if(l==r)
		return true;
	else
		return false;
}

void fins( long long data )
{

	if(Empty())
	{l = 0;r = 0;}
	else
		Q[++r] = data;
}


void rins( long long data )
{
	if(Empty())
	{l = 0;r = 0;}
	else if(l== 0)
		l=1000010-1;
	else
		l--;
	Q[l] = data ;
}

void rdel()
{
	if(ler())
	{l = -1;r=-1;}
	else if(l == 1000010-1)
		l = 0;
	else
		l++;
}


void fdel()
{
	if(ler())
	{l=-1;r=-1;}
	else if(r == 0)
		r=1000010-1;
	else
		r--;
}

void pushnode(long long data)
{
	while( l !=-1  && Q[l] > data )
	{
		rdel();
	}
	rins(data);
}

void popnode(long long data)
{
	if( l !=-1 && Q[r] == data)
		fdel();
}

long long int mintime(long long int n,long long int k,long long int ARR[])
{
	long long int ARR2[n],ARR3[n];
	ARR3[n-1]=ARR[n-1];
	ARR2[0] = ARR[0];
	pushnode(ARR2[0]);
	int j=1;
	while(j<k)
	{
		ARR2[j] = ARR[0] + ARR[j];
		ARR3[j] = ARR[0] + ARR2[j];
		ARR3[j]=ARR[j]+2;
		pushnode(ARR2[j]);
		j++;
	}
	j=k;
	while(j<n)
	{
		ARR2[j] = ARR[j] + Q[r];
		ARR3[j] = ARR[j] + ARR2[j];
		ARR3[j]=ARR[j]+2;
		popnode(ARR2[j-k]);
		pushnode(ARR2[j]);
		j++;
	}
	if(k >= n )
	{return ARR[0]+ARR[n-1]+n-1;}
	else
	{return (ARR2[n-1])+n-1;}
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
			printf("%lld ",mintime(n,mid,time));
      end=mid-1;
    }
    else
    {
			printf("%lld ",mintime(n,mid,time));
      start=mid+1;
    }
  }
  long long int min=cost[new];
  for(int i=new+1;i<n;i++)
  {
    if(cost[i]<min)
      min=cost[i];
  }
  printf("%lld\n",min);
  return 0;
}
