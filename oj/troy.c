#include<stdio.h>
#include<stdlib.h>


char arr[1010][1010];
int  arr2[1010][1010];


struct node {
	int data;
	struct node *next;
};
struct node *top=NULL;

void push(int data)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	if( top == NULL )
		top=temp;
	else
	{
		temp->next = top;
		top= temp;
	}
}

void pop()
{
	struct node* t;
	t = top;
	top = top->next;
	t->next = NULL;
	free(t);
}


int main(void)
{
	int m,n;
	scanf("%d %d",&m,&n);
	//char arr[m+5][n+5];
	//int  arr2[m+5][n+5];
	for(int i=0;i<m;i++)
	{
		int j;
		for( j=0;j<n;j++)
		{
			scanf(" %c",&arr[i][j]);
			if( arr[i][j]=='E')
				arr2[i][j]=0;
			else
				arr2[i][j]=1;
		}
	}
	/*for(int i=0;i<m;i++)
	  {
	  for(int j=0;j<n;j++)
	  {printf("%d ",arr2[i][j]);}
	  printf("\n");
	  }*/
	int temp;
	int max=0;
	int area=0;
	int i=0;
	int ans;
	while(i < n)
	{
		if( top == NULL || arr2[0][top->data] <= arr2[0][i] )
			push(i++);
		else
		{
			temp = arr2[0][top->data];
			pop();
			area = temp * i;
			if( top != NULL)
				area = temp * ( i - top->data - 1);
			if( area > max )
				max=area;
		}
	}
	while( top != NULL)
	{
		temp = arr2[0][top->data];
		pop();
		area = temp * i;
		if ( top != NULL)
			area = temp * ( i - top->data - 1);
		if( area > max)
			max = area;
	}
	ans=max;




	for(int j=1;j<m;j++)
	{
		for(int k=0;k<n;k++)
			if(arr2[j][k])
				arr2[j][k] += arr2[j-1][k];
		max=0;
		area=0;
		i=0;

		while(i < n)
		{
			if( top == NULL || arr2[j][top->data] <= arr2[j][i] )
				push(i++);
			else
			{
				temp = arr2[j][top->data];
				pop();
				area = temp * i;
				if( top != NULL)
					area = temp * ( i - top->data - 1);
				if( area > max )
					max=area;
			}
		}
		while( top != NULL)
		{
			temp = arr2[j][top->data];
			pop();
			area = temp * i;
			if ( top != NULL)
				area = temp * ( i - top->data - 1);
			if( area > max)
				max = area;
		}
		if(max > ans)
			ans=max;
	}
	printf("%d\n",ans);

	return 0;
}
