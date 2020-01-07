#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	long long int a[n],ans,min,minpt;
	long long int temp[n];
	for(int i=0;i<n;i++)
	{scanf("%lld",&a[i]);}
	if (k>=n) {
		ans=a[0]+a[n-1];
		printf("%lld",ans);
		return 0;
	}

	min=a[0];
	temp[0]=a[0];

	for(int i=1;i<=k;i++)
	{
		temp[i]=a[i]+min;
	}
	for(int i=k+1;i<n;i++)
	{
		if(i%k==1 || i>minpt+k)
		{
			int j=i-k;
			min=temp[j];
			while (j<i-1)
			{
				if(temp[j+1]<min)
				{min=temp[j+1];minpt=j;}
				j++;
			}
		}
		temp[i]=min+a[i];
	}

	printf("%lld\n",temp[n-1]);
	return 0;
}
