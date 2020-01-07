#include<stdio.h>
#include<stdlib.h>

struct node {
        char data;
        struct node *next;
};
struct node *top=NULL;

void push(char data)
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
	int n;
	scanf("%d",&n);
	char st[n];
	char new[n];
	scanf("%s",st);
	int i=0;
	char min=st[0];
	int minpt=0;
	int l=0;
	while(st[i]!='\0')
	{
		int k=i;
		minpt=i;
		min=st[i];
		
		for(int j=i;j<n;j++)
		{
			if(st[j]<min)
			{min=st[j];minpt=j;}
		}
		i=minpt;
		if(top == NULL)
		{
			new[l++]=st[minpt];
			for(k;k<minpt;k++)
				push(st[k]);
			i++;
		}
		else
		{
			while(top!=NULL)
			{
				if( top->data <= st[minpt] )
				{
					new[l++]=top->data;
					pop();
				}
				else
				{
					for(k;k<minpt;k++)
						push(st[k]);
					new[l++]=st[minpt];
					i++;
					break;
				}
			}
		}
	}

	while(top!=NULL)
	{
		new[l++]=top->data;
		pop();
	}
	for(int y=0;y<n;y++)
		printf("%c",new[y]);
	printf("\n");
}






