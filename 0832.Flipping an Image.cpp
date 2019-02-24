class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ret = 0;
        
        unordered_set<char> jewels(J.begin(), J.end());
        for (char c : S) if (jewels.count(c)) ret++;
        
        return ret;
    }
};