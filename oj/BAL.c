#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;int count=0;int flag=0;
	scanf("%d",&n);
	if(n%2==1)
	{
		char arr3[n];
		for(int i=0;i<n;i++)
			scanf("%c",&arr3[i]);
		printf("%d\n",-1);
		exit(0);
	}
	else
	{
		char arr[n];
		getchar();
		for(int i=0;i<n;i++)
		{
			scanf("%c",&arr[i]);
		}
		char arr2[n];
		for(int i=0;i<n;i++)
		{
			arr2[i]=arr[n-1-i];
		}
		for(int i=0;i<n/2;i++)
		{
			if(arr2[i]==arr[i])
			{
				if(arr[i]=='A')
					arr[n-1-i]='C';
				else if(arr[i]=='C')
					arr[n-1-i]='A';
				++count;
			}
		}
		for(int i=n/2;i<n;i++)
		{
			if(arr2[i]==arr[i])
			{flag=1;break;}
		}

		if(flag==1)
			printf("%d\n",-1);
		else
			printf("%d\n",count);
	}
	return 0;
}
