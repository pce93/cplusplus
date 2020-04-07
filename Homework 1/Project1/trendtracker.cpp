#include "trendtracker.h"
#include <fstream>
#include <vector>


Trendtracker::Trendtracker(string filename)
{
	Entry a;
	a.pop = 0;
	string line;
	ifstream f;
	char delim = ',';
	f.open(filename);
	while (getline(f, line, delim)) {
		a.hashtag = line;
		getline(f, line);
		a.pop = stoi(line.substr(line.find(",") + 1));
		E.push_back(a);
	}
	f.close();
}

void Trendtracker::insert(string ht, int pop)
{
	Entry temp;
	temp.hashtag = ht;
	temp.pop = pop;
	E.push_back(temp);
}

int Trendtracker::size()
{
	if (E.empty())
		return 0;
	else
		return E.size();
}

void Trendtracker::tweeted(string ht)
{		
	if (!E.empty()) {
		for (int i = 0; i < E.size(); i++) {
			if (E[i].hashtag == ht) {
				E[i].pop++;
			}
		}
	}
}

int Trendtracker::popularity(string name)
{
	if (E.empty())
		return -1;
	for (int i = 0; i < E.size(); i++) {
		if (E[i].hashtag == name)
			return E[i].pop;
	}
	return -1;
}




void Trendtracker::top_ten_trends(vector<string>& T)
{
	int x = 0;
	vector<Entry>temp = E;
	int j = 1;

	while (j <= 10) {

		for (int k = 0; k<temp.size() - j; k++)
		{
			if (temp[k].pop>temp[k + 1].pop)
			{
				x = temp[k].pop;
				temp[k].hashtag.swap(temp[k + 1].hashtag);
				temp[k].pop = temp[k + 1].pop;
				temp[k + 1].pop = x;
			}
		}
		j++;
	}
	if (!T.empty()) {
		T.clear();
	}
	T.push_back(temp[E.size() - 1].hashtag);
	T.push_back(temp[E.size() - 2].hashtag);
	T.push_back(temp[E.size() - 3].hashtag);
	T.push_back(temp[E.size() - 4].hashtag);
	T.push_back(temp[E.size() - 5].hashtag);
	T.push_back(temp[E.size() - 6].hashtag);
	T.push_back(temp[E.size() - 7].hashtag);
	T.push_back(temp[E.size() - 8].hashtag);
	T.push_back(temp[E.size() - 9].hashtag);
	T.push_back(temp[E.size() - 10].hashtag);
}


int Trendtracker::BiSearch(int pop)
{
	int miniPos;
	Entry temp;

	for (int i = 0; i < E.size(); i++)
	{
		miniPos = i;
		for (int j = i + 1; j < E.size(); j++)
		{
			if (E[j].pop < E[miniPos].pop)
			{
				miniPos = j;
			}
		}

		temp = E[miniPos];
		E[miniPos] = E[i];
		E[i] = temp;
	}
	int first = 0;
	int middle = 0;
	int last = E.size() - 1;
	int position = 0;
	while (first <= last) {
		middle = (first + last) / 2;
		if (E[middle].pop == pop) {
			position = middle;
			return position;
		}
		else if (E[middle].pop > pop)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return -1;
}

string Trendtracker::Inhashtag(int index)
{
	return E[index].hashtag;
}
