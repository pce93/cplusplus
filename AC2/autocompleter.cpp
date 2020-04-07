#include "autocompleter.h"

int max(int a, int b)
{
	return (a > b) ? a : b;
}

Autocompleter::Autocompleter()
{
}

void Autocompleter::insert(string x, int freq)
{
	Entry a; 
	a.s = x;
	a.freq = freq;
	if (root == NULL) {
		Node* A = new Node(a);
		root = A;
	}
	else {
		insert_recurse(a, root);
	}
}

int Autocompleter::size()
{
	return size_recurse(root);
}

void Autocompleter::completions(string x, vector<string>& T)
{
	T.clear();
	vector<Entry> R;
	completions_recurse(x, root, R);
	if (R.size() == 0)
		return;
	if (R.size() < 3) {
		if (R.size() == 1) {
			T.push_back(R[0].s);
			return;
		}
		else if (R[0].freq < R[1].freq) {
			T.push_back(R[1].s);
			T.push_back(R[0].s);
			return;
		}
		else {
			T.push_back(R[0].s);
			T.push_back(R[1].s);
			return;
		}
	}
	else {
		int a, b, c;
		a = b = c = 0;
		int first, second, third;
		first = second = third = INT_MIN;
		for (int i = 0; i < R.size(); i++) {
			if (R[i].freq > first) {
				third = second;
				c = b;
				second = first;
				b = a;
				first = R[i].freq;
				a = i;
			}
			else if (R[i].freq > second) {
				third = second;
				c = b;
				second = R[i].freq;
				b = i;
			}
			else if (R[i].freq > third) {
				third = R[i].freq;
				c = i;
			}
		}
		T.push_back(R[a].s);
		T.push_back(R[b].s);
		T.push_back(R[c].s);
	}
}

int Autocompleter::size_recurse(Node * root)
{
	if (root == NULL)
		return 0;
	else {
		return (size_recurse(root->left) + 1 + size_recurse(root->right));
	}
}

void Autocompleter::completions_recurse(string x, Node * root, vector<Entry>& C)
{
	if (root == NULL) {
		return;
	}
	size_t found = root->e.s.find(x);
	if (found == 0) {
		C.push_back(root->e);
		completions_recurse(x, root->left, C);
		completions_recurse(x, root->right, C);
	}
	else if (root->e.s > x)
		completions_recurse(x, root->left, C);
	else
		completions_recurse(x, root->right, C);
}

void Autocompleter::insert_recurse(Entry e, Node *& root)
{
	if (root->e.s > e.s) {
		if (root->left == NULL) {
			Node* A = new Node(e);
			root->left = A;
		}
		else
			insert_recurse(e, root->left);
	}
	else {
		if (root->right == NULL) {
			Node* B = new Node(e);
			root->right = B;
		}
		else
			insert_recurse(e, root->right);
	}
	root->height = 1 + max(height(root->left), height(root->right));
	rebalance(root);
}

void Autocompleter::rebalance(Node *& root)
{
	if (root == NULL)
		return;
	int balance = height(root->left) - height(root->right);
	if (balance > 1) {
		balance = height(root->left->left) - height(root->left->right);
		if (balance < 0) {
			left_rotate(root->left);
			right_rotate(root);
			return;
		}
		else{
			right_rotate(root);
			return;
		}
	}
	else if (balance < -1) {
		balance = height(root->right->left) - height(root->right->right);
		if (balance > 0) {
			right_rotate(root->right);
			left_rotate(root);
			return;
		}
		else {
			left_rotate(root);
			return;
		}
	}
}

void Autocompleter::right_rotate(Node *& root)
{
	if (root == NULL)
		return;
	Node* a = root;	
	Node* b = root->left;
	Node* br = b->right;
	

	root = b;
	b->right = a;
	a->left = br;

	a->height = max(height(a->left), height(a->right)) + 1;
	b->height = max(height(b->left), height(b->right)) + 1;
}

void Autocompleter::left_rotate(Node *& root)
{
	if (root == NULL)
		return;
	Node* a = root;
	Node* b = root->right;
	Node* bl = b->left;

	root = b;
	b->left = a;
	a->right = bl;

	a->height = max(height(a->left), height(a->right)) + 1;
	b->height = max(height(b->left), height(b->right)) + 1;
}