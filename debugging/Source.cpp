
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

class Entry
{
public:
	string s;
	long long int freq; // Real frequencies can be very big	
};



int main()
	{
		ifstream myfile("animals.txt");
		if (!myfile)
			cout << "error";
		list<Entry> myList;
		Entry a;
		string tmp;
		while (!myfile.eof()) {
			getline(myfile, a.s, ' ');
			getline(myfile, tmp);
			a.freq = stoll(tmp, 0);
			myList.push_back(a);
		}
		Entry b = myList.front();
		cout << b.s << b.freq;
		system("PAUSE");

		return 0;
	}

		