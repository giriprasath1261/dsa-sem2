#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	long long int n,k;
	long long int th,ans;
	scanf("%lld%lld%lld",&n,&k,&th);
	long long int start[n],speed[n];
	long long int pos[n],pos2[n];
	for(int i=0;i<n;i++)
	{scanf("%lld",&start[i]);}
	for(int i=0;i<n;i++)
	{scanf("%lld",&speed[i]);}


	long long int beg,end,mid,mid2;
	beg=0;
	end=th;
	while(beg<=end)
	{
		mid=(end+beg)/2;
		mid2=mid-1;
		for( int  i = 0; i < n; i++)
		{
			pos[i]=start[i]+speed[i]*mid;
			pos2[i]=start[i]+speed[i]*mid2;
		}
		long long int sum=0,sum2=0;
		for( int i = 0; i <=n-k; i++)
		{
			long long int max=pos[i];
			long long int max2=pos2[i];
			for(int j = 1; j<k; j++)
			{
				if(pos[i+j]>max)
				{max=pos[i+j];}
				if(pos2[i+j]>max2)
				{max2=pos2[i+j];}
			}
			sum+=max;
			sum2+=max2;
		}
		if(sum==th)
		{
			ans=mid+1;
			break;
		}
		else if(sum > th)
		{
			if(mid==0)
			{ans=mid;break;}
			else if(mid>0)
			{
				if(sum2 <= th)
				{
					ans=mid;
					break;
				}
				else
					end=mid-1;
			}
			end=mid-1;
		}
		else
		{
			beg=mid+1;
		}
	}

	printf("%lld\n",ans);
	return 0;
}
