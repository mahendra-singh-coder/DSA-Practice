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
int main()
{  
	do
	{
		int choice;
		printf("\nEnter your choice \n1.create \n2.displayforward \n3.displaybackward \n4.deletefromstart \n5.deletefromEnd \n6.Exit: \n");
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
				printf("EXIT...\n");
				break;
			default:
				printf("Invalid choice");
				break;
		}
		if(choice==6)
			break;
	}while(1);
	
	
  return 0;
}
