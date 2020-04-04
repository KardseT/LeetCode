// 274. H-Index
// Medium

// Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

// According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

// Example:

// Input: citations = [3,0,6,1,5]
// Output: 3 
// Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
//              received 3, 0, 6, 1, 5 citations respectively. 
//              Since the researcher has 3 papers with at least 3 citations each and the remaining 
//              two with no more than 3 citations each, her h-index is 3.
// Note: If there are several possible values for h, the maximum one is taken as the h-index.

// 求 h index，N 篇論文中有 h 篇論文引用數大於 h，且其餘論文的引用數小於 h

class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int h = 0;
    	sort(citations.begin(), citations.end(), greater<int>());

    	for (int i = 0; i < citations.size(); ++i)
    	{
    		if (citations[i] > h)
    			h++;
    	}
        return h;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for H-Index.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for H-Index.

// Related Topics
// Hash TableSort