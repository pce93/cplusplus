#include "trendtracker.h"

Trendtracker::Trendtracker()
{
}

void Trendtracker::insert(string ht)
{
	for (Entry e : E) {
		if (e.hashtag == ht)
			return;
	}
	Entry a;
	a.hashtag = ht;
	a.pop = 0;
	E.push_back(a);

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
	for (Entry &e : E) {
		if (e.hashtag == ht)
			e.pop++;
	}

}

int Trendtracker::popularity(string name)
{
	for (Entry e : E)
		if (e.hashtag == name)
			return e.pop;
	return -1;
}

string Trendtracker::top_trend()
{

	if (E.empty()) {
		return "";
	}
	else if (E.size() == 1)
		return E[0].hashtag;
	else {
		int high = E[0].pop;
		int place = 0;
		for (int i = 0; i < E.size(); i++) {
			if (high < E[i].pop) {
				high = E[i].pop;
				place = i;
			}
		}
		return E[place].hashtag;
	}

}

void Trendtracker::top_three_trends(vector<string>& T)
{
	while (!T.empty()) {
		T.pop_back();
	}

	int first = 0;
	int second = 0;
	int third = 0;
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	if (E.empty())
		return;
	else if (E.size() == 1) {
		T.push_back(E[0].hashtag);
		return;
	}
	else if (E.size() == 2) {
		if (E[0].pop > E[1].pop) {
			T.push_back(E[0].hashtag);
			T.push_back(E[1].hashtag);
			return;
		}
		else
			T.push_back(E[1].hashtag);
		T.push_back(E[0].hashtag);
		return;
	}
	else {
		for (int i = 0; i < E.size(); i++) {
			if (first < E[i].pop) {
				third = second;
				second = first;
				first = E[i].pop;
				p3 = p2;
				p2 = p1;
				p1 = i;
			}
			else if (second < E[i].pop) {
				third = second;
				second = E[i].pop;
				p3 = p2;
				p2 = i;
			}
			else if (third < E[i].pop) {
				third = E[i].pop;
				p3 = i;
			}
		}
		T.push_back(E[p1].hashtag);
		T.push_back(E[p2].hashtag);
		T.push_back(E[p3].hashtag);
	}

}

void Trendtracker::top_k_trends(vector<string>& T, int k)
{
	/*vector<Entry> A;
	while (!T.empty()) {
		T.pop_back();
	}
	if (E.empty())
		return;

	else
		for (int i = 0; i < E.size(); i++) {
			if (E[i].pop != 1)
				A.push_back(E[i]);
			if (A.size() > 1)
				for (int j = 0; j < A.size(); j++) {
					if (A[j].pop < A[j + 1].pop && (j + 1) < A.size()) {
						Entry temp = A[j];
						A[j] = A[j + 1];
						A[j + 1] = temp;
					}
				}
		}

	for (int i = 0; i <= k; i++) {
		T.push_back(A[i].hashtag);
	}*/
}
