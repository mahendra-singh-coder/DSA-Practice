import java.util.Scanner;
class Node
{
	public Node prev;
	public Node next;
	public int data;
}
class LinkedList
{
	Scanner kb=new Scanner(System.in);
	Node start;
	Node tail;
	Node temp=new Node();
	public LinkedList()
	{
		start=tail=null;
	}
	public void create()
	{
		
		System.out.print("Enter how Many Nodes You Want To Create : ");
		int n=kb.nextInt();
		for(int i=0;i<n;i++)
		{
			Node node = new Node();
			System.out.print("Enter data : ");
			node.data=kb.nextInt();
			if(start==null)
			{
				start=tail=node;
				node.prev=null;
				node.next=null;
			}
			else
			{
				temp=start;
				while(temp.next!=null)
				{
					temp=temp.next;
				}
				temp.next=node;
				node.next=null;
				tail=node;
			}
		}

	}
	public void traverse()
	{
		temp=start;
		while(temp!=null)
		{
			System.out.print(temp.data+" ");
			temp=temp.next;
		}
	}
}
class DoublyLinkedListExample
{
	public static void main(String []args)
	{
		LinkedList list=new LinkedList();
		list.create();
		list.traverse();
	}
}