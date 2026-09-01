import java.util.Scanner;

class Node
{
	public int data;
	public Node next;
}
class LinkedList
{
	Node start;
	public Node temp=new Node();
	public LinkedList()
	{
		start=null;
	}
	public void create()
	{
		Scanner kb=new Scanner(System.in);
		System.out.print("Enter How Much Node You want to create : ");
		int n=kb.nextInt();
		for(int i=0;i<n;i++)
		{
			Node node=new Node();
			
			System.out.print("Enter data : ");
			node.data=kb.nextInt();
			if(start==null)
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
class SinglyLinkedList
{
	public static void main(String []args)
	{
		LinkedList list=new LinkedList();
		list.create();
		list.traverse();
	}
}