class Solution {
public:
    int dp[101];
    int rob(vector<int>& nums)
    {
        memset(dp, -1, sizeof(dp));
        int i = 0;
        int ans = solve(i, nums);
        
        return ans;
        
    }
    
    int solve(int i, vector<int> nums)
    {
        if(i >= nums.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ans = 0;
        
        int choose = nums[i] + solve(i+2, nums);
        int not_choose = solve(i+1, nums);
        
        ans = max(choose, not_choose);
        
        return dp[i] = ans;
    }
};