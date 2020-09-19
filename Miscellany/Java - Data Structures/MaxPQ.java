/*
 * Max Priority Queue implemented using an array of fixed capacity
 *
 * Improvements:
 *		- Resizing array
 *		- Heapsort
 */

public class MaxPQ<T extends Comparable<T>>
{
	private T[] heap;
	private int CAPACITY;
	private int last = 0;
	private boolean hasMax = false;

	public MaxPQ(boolean hasMax)
	{
		this.hasMax = hasMax;
		CAPACITY = 2; 
		heap = (T[]) new Comparable[CAPACITY+1];
	}
	public MaxPQ(int max_cap)
	{
		this.hasMax = true;
		CAPACITY = max_cap;
		heap = (T[]) new Comparable[CAPACITY+1]; 
	}
	// TODO implement a resizing array MaxPQ constructor + resize() method

	// accessors & mutators
	public void insert(T new_entry)
	{
		// Grow if this item would increase beyond capacity
		// Or if hasMax, then delMin() or skip depending on value
		if (last == CAPACITY)
		{
			if (!hasMax)									resize(CAPACITY*2);
			// do not add if at max capacity and is less than min
			else if (new_entry.compareTo(heap[last]) < 0)	return;
			else											delMin();	
		}
		// Shrink if contents only fill 1/4 of array
		else if (!hasMax && CAPACITY/4 > last)
		{ resize(CAPACITY/2); }

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

		//BUGGY
			System.out.println("A"+k);
			System.out.println("B"+(k/2));
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
	
	private void delMin()
	{ heap[last--] = null; }
	
	private void resize(int cap)
	{
		CAPACITY = cap;
		T[] tmp = (T[]) new Comparable[CAPACITY+1];
		for (int i = 0; i < last; i++)
			tmp[i] = heap[i];
		heap = tmp;
	}
	
	// Tests
	public static void main(String[] args)
	{
		MaxPQ<Node> pq = new MaxPQ<Node>(false);
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
		pq.insert(new Node(new int[]{1,16}));
		pq.insert(new Node(new int[]{2,17}));
		pq.insert(new Node(new int[]{3,18}));
		pq.insert(new Node(new int[]{4,29}));
		pq.insert(new Node(new int[]{5,18}));
		pq.insert(new Node(new int[]{6,17}));
		pq.insert(new Node(new int[]{7,16}));
		pq.insert(new Node(new int[]{8,15}));
		pq.insert(new Node(new int[]{9,14}));
		pq.insert(new Node(new int[]{10,13}));
		pq.insert(new Node(new int[]{11,12}));
		pq.insert(new Node(new int[]{12,11}));
		
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