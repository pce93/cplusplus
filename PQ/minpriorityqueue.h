
#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

// NOTE: You may not include any other libraries!
#include <unordered_map>
#include <vector>
#include <utility> // Has pair and swap

using namespace std;

template <typename T>
class MinPriorityQueue
{
	// For the mandatory running times below:
	//
	// n is the number of elements in the MinPriorityQueue.
	//
	// Assume that the operations of unordered_map are O(1) time 
	// (they are average case, but not worst-case).

public:
	// Creates an empty MinPriorityQueue
	MinPriorityQueue()
	{
		// TODO
	}

	// Returns the number of elements in the MinPriorityQueue.
	//
	// Must run in O(1) time.
	int size()
	{
		return H.size();
	}

	// Pushes a new value x with priority p
	// into the MinPriorityQueue.
	//
	// Must run in O(log(n)) time.		 
	void push(T x, int p)
	{
		pair<T, int> p1;
		p1 = make_pair(x, p);
		H.push_back(p1);
		int i = H.size() - 1;
		I[x] = i;
		bubbleUp(i);
	}

	// Returns the value at the front of the MinPriorityQueue.
	// Undefined behavior if the MinPriorityQueue is empty.
	// 
	// Must run in O(1) time.
	T front()
	{
		if (!H.empty())
		{
			return H[0].first;
		}
	}

	// Removes the value at the front of the MinPriorityQueue.
	// Undefined behavior if the MinPriorityQueue is empty.
	//
	// Must run in O(log(n)) time. 
	void pop()
	{
		if (H.size() == 0)
			return;
		if (H.size() == 1)
		{
			H.pop_back();
			I.clear();
			return;
		}
		swap(I[H[0].first], I[H[H.size() - 1].first]);
		swap(H[0], H[H.size() - 1]);
		I.erase(H[H.size() - 1].first);
		H.pop_back();

		int i = 0;
		while (i < H.size())
		{
			if (lchild(i) > H.size() - 1)
				return;
			else if (lchild(i) <= H.size() - 1 && rchild(i) > H.size() - 1)
			{
				if (H[i].second > H[lchild(i)].second)
				{
					swap(I[H[lchild(i)].first], I[H[i].first]);
					swap(H[lchild(i)], H[i]);
					i = lchild(i);
					return;
				}
				else
					return;
			}
			if (H[lchild(i)].second > H[rchild(i)].second)
			{
				swap(I[H[rchild(i)].first], I[H[i].first]);
				swap(H[rchild(i)], H[i]);
				i = rchild(i);
				if (lchild(i) > H.size() - 1)
					return;
			}
			else
			{
				swap(I[H[lchild(i)].first], I[H[i].first]);
				swap(H[lchild(i)], H[i]);
				i = lchild(i);
				if (lchild(i) > H.size() - 1)
					return;
			}
		}
	}

	// If x is in the MinPriorityQueue 
	// with current priority at least new_p,  
	// then changes the priority of x to new_p.
	// Undefined behavior otherwise.
	//
	// Must run in O(log(n)) time. 
	void decrease_key(T x, int new_p)
	{
		if (I[x]) {
		int y = H[I[x]].second;
		H[I[x]].second = new_p;
		if (y > new_p) {
		bubbleUp(I[x]);
		}
		else
		{
		int i = I[x];
		while (true) {
		if (H[lchild(i)].second > H[rchild(i)].second)
		{
		swap(I[H[rchild(i)].first], I[H[i].first]);
		swap(H[rchild(i)], H[i]);
		i = rchild(i);
		if (lchild(i) > H.size() - 1)
		return;
		}
		else
		{
		swap(I[H[lchild(i)].first], I[H[i].first]);
		swap(H[lchild(i)], H[i]);
		i = lchild(i);
		if (lchild(i) > H.size() - 1)
		return;
		}
		}
		}
		}
	}
	void bubbleUp(int i)
	{
		if (i == 0)
			return;
		int c = i;
		while (H[c].second < H[parent(c)].second)
		{
			swap(I[H[c].first], I[H[parent(c)].first]);
			swap(H[c], H[parent(c)]);
			c = parent(c);
			if (c == 0)
				return;
		}

	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	int lchild(int i)
	{
		return (i * 2) + 1;
	}
	int rchild(int i)
	{
		return (i * 2) + 2;
	}
private:
	// You don't need any other instance variables,
	// but you can add some if you want to.
	vector< pair<T, int> > H; // The heap.
	unordered_map<T, int> I;  // Maps values to their indices in H.
};

#endif 

