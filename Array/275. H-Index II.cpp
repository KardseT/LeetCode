// 275. H-Index II
// Medium

// Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

// According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

// Example:

// Input: citations = [0,1,3,5,6]
// Output: 3 
// Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
//              received 0, 1, 3, 5, 6 citations respectively. 
//              Since the researcher has 3 papers with at least 3 citations each and the remaining 
//              two with no more than 3 citations each, her h-index is 3.
// Note:

// If there are several possible values for h, the maximum one is taken as the h-index.

// Follow up:

// This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
// Could you solve it in logarithmic time complexity?

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int left = 0, right = len-1;

        while (left <= right)
       	{
       		int mid = (right-left)/2 + left;

       		if (citations[mid] > len - mid)
       			right = mid - 1;
       		else if (citations[mid] < len - mid)
 				left = mid + 1;
       		else
       			return len-mid;
       	}
       	
       	return len - left;
    }
};

// Runtime: 20 ms, faster than 87.68% of C++ online submissions for H-Index II.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for H-Index II.

// Related Topics
// Binary Search