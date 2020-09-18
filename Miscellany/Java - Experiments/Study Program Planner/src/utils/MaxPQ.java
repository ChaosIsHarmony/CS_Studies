package utils;

public class MaxPQ<T extends Comparable<T>>
{
	private T[] heap;
	private final int CAPACITY;
	private int last = 0;
	private boolean hasMax = false;

	public MaxPQ()
	{ CAPACITY = 10; heap = (T[]) new Comparable[CAPACITY+1]; hasMax = true; }
	public MaxPQ(int max_cap)
	{ CAPACITY = max_cap; heap = (T[]) new Comparable[CAPACITY+1]; hasMax = true; }
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
		
		heap[++last] = new_entry; swim(last); }
	
	public T getMax()
	{ return heap[1]; }
	public boolean isEmpty()
	{ return last == 0; }
	public T delMax()
	{ T tmp = heap[1]; heap[1] = heap[last]; heap[last--] = null; sink(1); return tmp; }
	
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
	private void delMin()
	{ heap[last--] = null; }
}