#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node Node;
Node *start=NULL;
void create()
{
	int i,n;
	printf("\nkitne Node Ki list Banani hai : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		Node *node = malloc(sizeof(Node));
		printf("\nEnter data : ");
		scanf("%d",&node->data);
		node->next=NULL;
		if(start == NULL)
		{
			start=node;
		}
		else
		{
			Node *temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=node;
		}
	}
}
void Reverse(Node *temp)
{
	int d;
	if(temp==NULL)
	return;
	
	d=temp->data;
	temp=temp->next;
	Reverse(temp);
	printf("%d ",d);
}
int main()
{
	create();
	Node *temp=start;
	Reverse(temp);
}
