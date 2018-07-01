#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;

        for(int i=0; i < nums.size(); ++i)
        {
            int complement = target - nums.at(i);
            if(hash.find(complement) != hash.end())
            {
                result.push_back(hash[complement]);
                result.push_back(i);
            }
            hash.insert(pair<int, int>(nums.at(i), i));
        }

        if(result.empty())
            result = vector<int>(2, 0);
            
        return result;
    }
};