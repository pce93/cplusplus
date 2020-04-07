#include <iostream>
#include "trendtracker.h"



using namespace std;


Trendtracker::Trendtracker()
{

}

void Trendtracker::add_hashtag(string ht)
{

	for (Entry e : E) {
		if (e.hashtag == ht) {
			return;
		}
	}
	Entry a;
	a.hashtag = ht;
	a.count = 0;
	E.push_back(a);
	
	
}

int Trendtracker::size()
{
	return E.size();
}

void Trendtracker::tweeted(string ht)
{
	for (Entry &t : E) {
		if (t.hashtag == ht) {
			t.count++;
		//implement binary search here to sort vector	
		}

	}	

	}



int Trendtracker::popularity(string name)
{
	for (Entry p : E) {
		if (p.hashtag == name)
			return p.count;
	}
	return -1;
}

string Trendtracker::top_trend()

{
	return E[0].hashtag;
	
}

void Trendtracker::trending(int k, vector<string>& T)
{
}

int Trendtracker::S_index(string ht)
{
	return 0;
}

int Trendtracker::lowest_E_index_with_count(int count)
{
	return 0;
}

