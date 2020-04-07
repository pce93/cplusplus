#include <iostream>
#include "autocompleter.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <list>
#include <iterator>

using namespace std;


int main()
{
	Autocompleter("animals.txt");
	system("PAUSE");

	return 0;
}

Autocompleter::Autocompleter(string filename)
{
	ifstream myfile(filename);
	if (!myfile)
		cout << "error";
	list<Entry> myList;
	Entry a;
	string tmp;
	while (true) {
		getline(myfile, a.s, ' ');
		getline(myfile, tmp, '\n');
		a.freq = stoll(tmp, 0);
		if (myfile.eof()) break;
		myList.push_back(a);
		
	}
	
	//myList.sort([](const Entry &f, const Entry &s) {return f.s < s.s; });
	/*for (auto const& i : myList) {
		cout << i.s << " " << i.freq;
		
	}*/
	for (auto const& i : myList) {
		Node* node = new Node(i);
		if (root == NULL) {
			root = node;
			continue;
		}

		else {
			Node** cur = &root;			
			while (*cur) {
				if ((*cur)->e.s.compare(node->e.s) < 0)
					cur = &(*cur)->right;
				else
					cur = &(*cur)->left;
			}
			*cur = node;
		}
	}

	/*while (root->left != NULL) {
		Node* cur = root->left;
		cout << cur->e.s << " " << cur->e.freq << endl;
	}*/
	
}



int Autocompleter::size()
{
	return 0;
}

int Autocompleter::completion_count(string x)
{
	return 0;
}

void Autocompleter::completions(string x, vector<string>& C)
{
}
