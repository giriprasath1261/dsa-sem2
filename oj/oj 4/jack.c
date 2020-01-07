# include<stdio.h>
#define MAX 1000010

long long A[MAX];
int left = -1;
int right = -1;

void frontPush( long long data )
{

	if (left == -1)
	{
		left = 0;
		right = 0;
	}
	else
		right = right+1;
	A[right] = data;
}

void rearPush( long long data )
{
	if (left == -1)
	{
		left = 0;
		right = 0;
	}
	else if(left== 0)
		left=MAX-1;
	else
		left=left-1;

	A[left] = data ;
}

void rearPop()
{
	if(left == right)
	{
		left = -1;
		right=-1;
	}
	else if(left == MAX-1)
		left = 0;
	else
		left = left+1;
}

int notEmpty()
{
	if(left == -1)
		return 0;
	else
		return 1;
}

void frontPop()
{
	if(left == right)
	{
		left = -1;
		right=-1;
       	}
	else if(right == 0)
		right=MAX-1;
	else
		right=right-1;
}

void insertNode(long long data)
{
	while( left !=-1  && A[left] > data )
		rearPop();
	rearPush(data);
}

void deleteNode(long long data)
{
	if( left !=-1 && A[right] == data)
		frontPop();
}

//Display Queue copy-pasted from internet for debugging purpose
/*void display_queue()
{	int front_pos = left,rear_pos = right;
	if(left == -1)
	{	printf("Queue is empty\n");
		return;	 }
	printf("Queue elements :\n");
	if( front_pos <= rear_pos )
	{	while(front_pos <= rear_pos)
		{	printf("%lld ",A[front_pos]);
			front_pos++;	}	}
	else
	{	while(front_pos <= MAX-1)
		{	printf("%lld ",A[front_pos]);
			front_pos++;	}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{	printf("%lld ",A[front_pos]);
			front_pos++;
		}
	}
	printf("\n");
}*/

int main(void)
{
	int n,k; scanf("%d%d",&n,&k);
	long long S[n], DP[n];

	for(int i=0; i<n; i++)
		scanf("%lld",&S[i]);

	DP[0] = S[0];
	insertNode(DP[0]);

	for(int i=1; i<k; i++)
	{
		DP[i] = S[0] + S[i];
		insertNode(DP[i]);
		//display_queue();
		//printf("%lld ",A[right]);
	}

	for(int i=k; i<n; i++)
	{
		DP[i] = S[i] + A[right];
		deleteNode(DP[i-k]);
		//display_queue();
		//printf("%lld ",A[right]);
		insertNode(DP[i]);
	}

	printf("%lld\n",(k >= n ) ? S[0] + S[n-1] +n-1 : (DP[n-1])+n-1);
	return 0;
}

//Naren Akash,R J - 2018111020
//February 02, 2018 - Sunday
//International Institute of Information Technology, Hyderabad
