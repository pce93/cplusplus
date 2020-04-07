#include <iostream>
#include "trendtracker.h"



using namespace std;


Trendtracker::Trendtracker()
{

}

void Trendtracker::add_hashtag(string ht)
{

	for (Entry e: E) {
		if (e.hashtag == ht) {
			return;
		}

}
	
	Entry a;
	a.hashtag = ht;
	E.push_back(a);
	

	/*Entry a;
	a.hashtag = ht;
	E.push_back(a);*/
	
}

int Trendtracker::size()
{
	return E.size();
}

void Trendtracker::tweeted(string ht)
{

}

int Trendtracker::popularity(string name)
{
	return 0;
}

string Trendtracker::top_trend()
{
	return string();
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

