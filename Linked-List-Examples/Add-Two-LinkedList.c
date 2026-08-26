#include<stdio.h>
#include<stdlib.h>
struct Node1
{
	int data1;
	struct Node1 *next1;
};
typedef struct Node1 Node1;
Node1 *start1=NULL;
struct Node2
{
	int data2;
	struct Node2 *next2;
};
typedef struct Node2 Node2;
Node2 *start2=NULL;
void create1()
{
	int i,n;
	printf("\nkitne Node Ki list Banani hai : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		Node1 *node = malloc(sizeof(Node1));
		printf("\nEnter data : ");
		scanf("%d",&node->data1);
		node->next1=NULL;
		if(start1 == NULL)
		{
			start1=node;
		}
		else
		{
			Node1 *temp=start1;
			while(temp->next1!=NULL)
			{
				temp=temp->next1;
			}
			temp->next1=node;
		}
	}
}
void create2()
{
	int i,n;
	printf("\nkitne Node Ki list Banani hai : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		Node2 *node = malloc(sizeof(Node2));
		printf("\nEnter data : ");
		scanf("%d",&node->data2);
		node->next2=NULL;
		if(start2 == NULL)
		{
			start2=node;
		}
		else
		{
			Node2 *temp=start2;
			while(temp->next2!=NULL)
			{
				temp=temp->next2;
			}
			temp->next2=node;
		}
	}
}
void add()
{
	int data;
	int  carry=0;
	Node1 *temp=start1;
	Node2 *semp=start2;
	while(temp!=NULL && semp!=NULL)
	{
		data=temp->data1+semp->data2+carry;
		if(temp->next1==NULL)
		{
			data=data;
		}
		else if(data >= 10)
		{
			
		    data = data % 10;
		    carry = 1;
		}
		else
		{
		    carry = 0;
		}
		temp->data1=data;
		temp=temp->next1;
		semp=semp->next2;
	}
}
void traverse()
{
	Node1 *temp=start1;
	while(temp!=NULL)
	{
		printf("%d ",temp->data1);
		temp=temp->next1;
	}
}
int main()
{
	create1();
	create2();
	add();
	traverse();
	return 0;
}

