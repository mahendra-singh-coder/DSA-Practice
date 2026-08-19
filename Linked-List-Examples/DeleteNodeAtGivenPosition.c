#include<stdio.h>
#include<stdlib.h>
struct Node
{  int data;
  struct Node *next,*prev;  
};
typedef struct Node Node;
Node *start=NULL,*tail=NULL;

void insertatbegining()
{  Node *node=malloc(sizeof(Node));
  printf("\nEnter data : ");
  scanf("%d",&node->data);
  node->next=node->prev=NULL;
  if(start==NULL)
    start=tail=node;
  else
  {  node->next=start;
    start->prev=node;
    start=node;
  }
}
void insertatlast()
{  Node *node=malloc(sizeof(Node));
  printf("\nEnter data : ");
  scanf("%d",&node->data);
  node->next=node->prev=NULL;
  if(start==NULL)
    start=tail=node;
  else
  {  node->prev=tail;
    tail->next=node;
    tail=node;
  }
}
void create()
{  int n,i;
  printf("\nHow many nodes you want to create in the list : ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {  insertatlast();
  }
}
void displayforward()
{  if(start==NULL)
    printf("\nList empty\n");
  else
  {  printf("\nList is ( start to tail )\n");
    Node *temp=start;
    while(temp!=NULL)
    {  printf("%d ",temp->data);
      temp=temp->next;
    }
  }
}
void displaybackward()
{  if(start==NULL)
    printf("\nList empty\n");
  else
  {  printf("\nList is (tail to start)\n");
    Node *temp=tail;
    while(temp!=NULL)
    {  printf("%d ",temp->data);
      temp=temp->prev;
    }
  }
}
void deletefromstart()
{
  if(start==NULL)
    printf("\nList empty");
  else if(start==tail)
  {  printf("\n%d delete from begining of the list",start->data);
    free(start);
    start=tail=NULL;
  }
  else
  {
    printf("\n%d delete from begining of the list",start->data);
    Node *temp=start;
    start=start->next;
    start->prev=NULL;
    temp->next=NULL;
    free(temp);
  }
}
void deletefromEnd()
{
  if(start==NULL)
    printf("\nList empty");
  else if(start==tail)
  {  printf("\n%d delete from last of the list",tail->data);
    free(start);
    start=tail=NULL;
  }
  else
  {
    printf("\n%d delete from last of the list",tail->data);
    Node *temp=tail;    
    tail=tail->prev;
    tail->next=NULL;
    temp->next=NULL;
    free(temp);
  }
}
void deleteGivenNode()
{
	
	int pos,i;
	int count=1;
	Node *temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		count++;
	}
	printf("Enter position you want to delete : ");
	scanf("%d",&pos);
	if(count==0)
	{
		printf("\nList is empty...");
	}
	else if(pos<1 || pos>count)
	{
		printf("Deletion failed...\n");
	}
	else if(pos==1)
	{
		deletefromstart();
	}
	else if(pos==count)
	{
		deletefromEnd();
	}
	else if(pos>1)
	{
		Node *temp=start;
		for(i=1;i<pos;i++)
		{
			temp=temp->next;
		}
		
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		temp->next=NULL;
		temp->prev=NULL;
		printf("\n%d Deleted Successfull...",temp->data);
		free(temp);
		printf("\nDeletion Successfull...");
	}
	
}
int main()
{  int n;
	do
	{
		int choice;
		printf("\nEnter your choice \n1.create \n2.displayforward \n3.displaybackward \n4.deletefromstart \n5.deletefromEnd \n6.deleteGivenNode \n7.Exit: \n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				displayforward();
				break;
			case 3:
				displaybackward();
				break;
			case 4:
				deletefromstart();
				break;
			case 5:
				deletefromEnd();
				break;
			case 6:
				deleteGivenNode();
				break;
			case 7:
				printf("EXIT...\n");
				break;
			default:
				printf("Invalid choice");
				break;
		}
		if(choice==7)
			break;
	}while(1);
	
	
  return 0;
}
