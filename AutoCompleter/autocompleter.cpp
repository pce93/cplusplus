#include "autocompleter.h"
#include <iostream>
#include <fstream>

Autocompleter::Autocompleter(string filename)
{
	ifstream file;
	file.open(filename);
	if (!file) {
		cout << "Unable to open file" << endl;
		
	}/*
	vector <Entry> list;
	Entry input;
	while (!file.eof()) {
		cin >> input.s;
		cin >> input.freq;
		list.push_back(input);
	}*/
}

int Autocompleter::size()
{
	int count = 0;
	
	Entry a;
	while (!dict.eof()) {
		dict >> a.s;

		count++;
	}

	return count;
}

int Autocompleter::completion_count(string x)
{
	return 0;
}

void Autocompleter::completions(string x, vector<string>& C)
{
}





int Autocompleter::size_recurse(Node * root)
{
	return 0;
}

int Autocompleter::completion_count_recurse(string x, Node * root)
{
	return 0;
}

void Autocompleter::completions_recurse(string x, Node * root, vector<Entry>& E)
{
}
