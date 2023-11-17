class Solution {
public:
    int minPairSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int i = 0;
        int j = n-1;
        
        int sum = 0;
        while(i < j)
        {
            sum = max(sum, nums[i]+nums[j]);
            i++;
            j--;
        }
        
        return sum;
    }
};