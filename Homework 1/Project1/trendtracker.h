
#ifndef TRENDTRACKER_H
#define TRENDTRACKER_H

#include <vector>
#include <string>

using namespace std;

class Trendtracker
{
	// For the mandatory running times below:
	// n is the number of hashtags in the Trendtracker.

	public:
		/* Creates a Trendtracker containing hashtags 
		   found in the provided file.
		   The file is promised to have the following format: 
		  
		   string1, popularity
		   string2, popularity 
		   ...
		   stringN, popularity
		 
		   where string1 < string2 < ... < stringN 
		   
		   Must run in O(n) time. */

		Trendtracker(string filename);

		/* Inserts a hashtag of the popularity pop into the Trendtracker.
		   If the input hashtag ht exists in Trendtracker, add max{pop, 0} to 
		   the pop value of this hashtage in vector E. 
		   Otherwise, create a new Entry type temp with hashtag equal to ht 
		   and pop equal the maximum value of zero and input pop. 
        
		   Must run in O(n) time.
		*/

		void insert(string ht, int pop);

		/* Return the number of hashtags in the Trendtracker.
		
		   Must run in O(1) time.*/

		int size();

		/* Adds 1 to the total number times a hashtag has been tweeted.
		   If the hashtag does not exist in TrendTracker, does nothing.
		 
		   Must run in O(n) time. 
		*/

		void tweeted(string ht);

		/* Returns the number of times a hashtag has been tweeted.
		   If the hashtag does not exist in Trendtracker, returns -1.
		 
		   Must run in O(n) time. 
		*/

		int popularity(string name);

		/* Fills the provided vector with the 10 most-tweeted hashtags, 
		   in order from most-tweeted to least-tweeted.
		 
		   If there are fewer than 10 hashtags, then the vector is filled
		   with all hashtags (in most-tweeted to least-tweeted order).

		   Meanwhile, store the indices in vector S 
		   in an nonincreasing order of popularity (i.e., in most-tweeted to least-tweeted order)
		 
		   Must run in O(n) time. 
		*/

		void top_ten_trends(vector<string> &T); 				


        /* 
           Do binary search on S by the given popularity pop; 
           Returns the index of E containing an Entry X with X.pop equal to the given popularity pop;
		   If no such hashtag is found, returns -1.    
		*/

		int BiSearch(int pop);


        /* 
           Return E[index].hashtag 
           If index is out of range, returns "/n Error: Index is Out Of Range".    
		*/

		string Inhashtag(int index);




	private: 
		// A struct representing a hashtag and 
		// the number of times it has been tweeted.
		struct Entry
		{
			public:
				string hashtag;
				int pop;
		};


		// Entries containing each hashtag and its popularity.
		vector<Entry> E; 


		/* Stores indices of the ten most-tweeted entries in E.  */

		vector<int> S;  


};

#endif 

