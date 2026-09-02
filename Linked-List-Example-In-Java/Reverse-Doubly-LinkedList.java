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
}
class ReverseDoublyLinkedList
{
	public static void main(String []args)
	{
		LinkedList list =new LinkedList();
		list.create();
		list.traverse();
		list.reverse();
	}
}