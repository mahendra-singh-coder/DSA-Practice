import java.util.Scanner;
class Node
{
	public Node next;
	public Node prev;
	public int data;
	
}
class LinkedList
{
	Node start;
	Node tail;
	public LinkedList()
	{
		start=tail=null;
	}
	Node temp=new Node();
	public void create()
	{

		Scanner kb = new Scanner(System.in);
		System.out.print("Enter How Much Node You Want To Create : ");
		int n=kb.nextInt();
		for(int i=0;i<n;i++)
		{
			Node node=new Node();
			System.out.print("Enter data : ");
			node.data=kb.nextInt();
			if(start==null)
			{
				start=tail=node;
				node.next=null;
				node.prev=null;
			}
			else
			{
				temp=start;
				while(temp.next!=null)
				{
					temp=temp.next;
				}
				temp.next=node;
				tail=node;
				node.next=null;
				node.prev=temp;
			}
		}
	}
	public void traverse()
	{
		System.out.print("\nLinked list [Head to Tail] ->");
		temp=start;
		while(temp!=null)
		{
			System.out.print(temp.data+" ");
			temp=temp.next;
		}
	}
	public void reverse()
	{
		System.out.print("\nLinked list [Tail to Head] -> ");
		temp=tail;
		while(temp!=null)
		{
			System.out.print(temp.data+" ");
			temp=temp.prev;
		}
	}
	public void insertAtEnd()
	{
		System.out.println("Insert at End ");
		Scanner kb = new Scanner(System.in);
		Node node=new Node();
		System.out.print("Enter Data : ");
		node.data=kb.nextInt();
		temp=tail;
		if(start==null)
		{
			start=tail=node;
			node.next=null;
			node.prev=null;
		}
		else
		{
			temp=tail;
			temp.next=node;
			node.next=null;
			node.prev=temp;
			tail=node;
		}
	}
}
class InsertAtEndLinkedListExample
{
	public static void main(String []args)
	{
		Scanner kb =new Scanner(System.in);
		LinkedList list =new LinkedList();
		do
		{
			System.out.print("\nYour Choice's \n1.create\n2.insertAtEnd\n3.Traverse\n4.Reverse\n5.Exit\nEnter Your Choice : ");
			int choice=kb.nextInt();
			switch(choice)
			{
			case 1:
				list.create();
				break;
			case 2:
				list.insertAtEnd();
				break;
			case 3:
				list.traverse();
				break;
			case 4:
				list.reverse();
				break;
			case 5:
				System.out.print("Exiting...");
				break;
			default:
				System.out.print("Invalid Choice...");
				break;
			}
			if(choice==5)
				break;
		}while(true);
	}
}