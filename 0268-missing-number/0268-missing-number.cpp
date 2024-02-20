class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int sum = 0;
        int n = nums.size();
        
        int tSum = ((n + 1) * n)/2;
        
        for(auto x: nums)
            tSum -= x;
        
        return tSum;
        
    }
};