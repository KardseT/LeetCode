// 80. Remove Duplicates from Sorted Array II
// Medium

// Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Given nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

// It doesn't matter what you leave beyond the returned length.
// Example 2:

// Given nums = [0,0,1,1,1,1,2,3,3],

// Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

// It doesn't matter what values are set beyond the returned length.
// Clarification:

// Confused why the returned value is an integer but your answer is an array?

// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

// Internally you can think of this:

// // nums is passed in by reference. (i.e., without making a copy)
// int len = removeDuplicates(nums);

// // any modification to nums in your function would be known by the caller.
// // using the length returned by your function, it prints the first len elements.
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        	return 0;

        if (nums.size() == 1)
        	return 1;

        int i = 0, count = 1;
        for(int index = 1; index < nums.size(); ++index)
        {
        	if (nums[index] != nums[i])
        	{
        		i += 1;
    			nums[i] = nums[index];
    			count = 1;
        	}
        	else if (nums[index] == nums[i] && count < 2)
        	{
        		i += 1;
        		nums[i] = nums[index];
        		++count;
        	}
        }

        return i+1;
    }
};


// time space = O(n)
// Runtime: 12 ms, faster than 78.39% of C++ online submissions for Remove Duplicates from Sorted Array II.
// Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Remove Duplicates from Sorted Array II.


// 高手版本
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};

// Runtime: 12 ms, faster than 78.39% of C++ online submissions for Remove Duplicates from Sorted Array II.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Remove Duplicates from Sorted Array II.


// Just want to confirm, this solution can be easily generalized to "at most K duplicates", right?

// int removeDuplicates(vector<int>& nums, int k) {
//     int i = 0;
//     for (int n : nums)
//         if (i < k || n > nums[i-k])
//             nums[i++] = n;
//     return i;
// }