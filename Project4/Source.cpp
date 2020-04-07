#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

bool subset_sum(set<int> &partial, set<int>::iterator it, set<int> &S, int w)
{
	if (it == S.end()) {
		int tot = 0;
		for (int x : partial)
			tot += x;
		return (tot == w);
	}

	int cur = *it;
	++it;
	if (subset_sum(partial, it, S, w))
		return true;
	partial.insert(cur);
	if (subset_sum(partial, it, S, w))
		return true;
	partial.erase(cur);
	return false;
}

int main()
{
	set<int> S{ 1,4,5,8,11,16,17,22, 23 };
	set<int> partial;
	cout << "The set{1,4,5,8,11,16,17,22, 23 } sums to 30: ";
	cout << subset_sum(partial, S.begin(), S, 24) << endl;
	system("PAUSE");
	return 0;

}
