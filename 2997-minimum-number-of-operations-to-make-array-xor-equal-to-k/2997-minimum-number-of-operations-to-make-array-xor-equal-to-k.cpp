class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        int xorSum = 0;
        
        for(int i: nums)
            xorSum ^= i;
        
        xorSum ^= k;
        
        return __builtin_popcount(xorSum);
        
    }
};