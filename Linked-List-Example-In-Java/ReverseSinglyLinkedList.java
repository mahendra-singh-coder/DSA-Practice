import java.util.Scanner;

class Node
{
	public int data;
	public Node next;
}
class LinkedList
{
	Scanner kb=new Scanner(System.in);
	public Node start;
	public Node temp=new Node();
	LinkedList()
	{
		start=null;
	}
	public void create()
	{
		System.out.print("Enter How much Node you want to create : ");
		int n=kb.nextInt();

		for(int i=0;i<n;i++)
		{
			Node node=new Node();
			System.out.print("Enter data : ");
			node.data=kb.nextInt();
			if(start == null)
			{
				start=node;
			}
			else
			{
				temp=start;
				while(temp.next!=null)
				{
					temp=temp.next;
				}
				temp.next=node;
			}
		}
	}
	void reverse(Node temp)
	{
		int d;
		if(temp==null)
			return;
		d=temp.data;
		temp=temp.next;
		reverse(temp);
		System.out.print(d+" ");
	}
}
class ReverseLinkedList
{
	public static void main(String []args)
	{
		LinkedList list =new LinkedList();
		list.create();
		System.out.println("Linked list in Reverse Order -> ");
		list.reverse(list.start);
	}
}