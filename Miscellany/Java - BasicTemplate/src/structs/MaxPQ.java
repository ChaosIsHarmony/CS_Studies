/*
* TODO: explain purpose of structure
*/

package structs;

// Only keeps top ten by default, but can change to capacity of client's choice
public class MaxPQ<T extends Comparable<T>>
{
	private T[] heap;
	private final int CAPACITY;
	private int last = 0;
	private boolean hasMax = false;

	public MaxPQ() { CAPACITY = 10; heap = (T[]) new Comparable[CAPACITY+1]; hasMax = true; }
	public MaxPQ(int max_cap) { CAPACITY = max_cap; heap = (T[]) new Comparable[CAPACITY+1]; hasMax = true; }
	// TODO implement a resizing array MaxPQ constructor + resize() method

	// accessors & mutators
	public void insert(T new_entry)
	{ 
		if (hasMax)
		{
			// do not add if at max capacity and is less than min
			if (last == CAPACITY && new_entry.compareTo(heap[last]) < 0)	return;
			else if (last == CAPACITY)										delMin();
		}
		
		heap[++last] = new_entry;
		swim(last);
	}
	
	public T getMax() { return heap[1]; }
	
	public boolean isEmpty() { return last == 0; }
	
	// private helper methods
	private void sink(int k)
	{
		while (2*k <= last)
		{
			int j = 2*k;
			if (j < last && less(j, j+1))	j++;
			if (!less(k, j))				break;
			exch(k, j);
			k = j;
		}
	}
		
	private void swim(int k)
	{
		while (k > 1 && less(k/2,k))
		{
			exch(k, k/2);
			k = k/2;
		}
	}

	private boolean less(int a, int b)
	{ return heap[a].compareTo(heap[b]) < 0; }
	private void exch(int a, int b)
	{ T tmp = heap[a]; heap[a] = heap[b]; heap[b] = tmp; }
	private void delMin() { heap[last--] = null; }
	
	
	// Tests
	public static void main(String[] args)
	{
		MaxPQ<Node> pq = new MaxPQ<Node>();
		pq.insert(new Node(new int[]{1,6}));
		pq.insert(new Node(new int[]{2,7}));
		pq.insert(new Node(new int[]{3,8}));
		pq.insert(new Node(new int[]{4,19}));
		pq.insert(new Node(new int[]{5,8}));
		pq.insert(new Node(new int[]{6,7}));
		pq.insert(new Node(new int[]{7,6}));
		pq.insert(new Node(new int[]{8,5}));
		pq.insert(new Node(new int[]{9,4}));
		pq.insert(new Node(new int[]{10,3}));
		pq.insert(new Node(new int[]{11,2}));
		pq.insert(new Node(new int[]{12,1}));
		
		System.out.println(pq.getMax().arr[1]);
	}
	
	private static class Node implements Comparable<Node>
	{
		int[] arr;
		public Node(int[] arr) { this.arr = arr; }
		@Override
		public int compareTo(Node that)
		{
			if (this.arr[1] > that.arr[1])	return 1;
			if (this.arr[1] < that.arr[1])	return -1;
			else							return 0;
		}
	}
}