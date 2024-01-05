class Solution {
public:
    int dp[10001];
    int lengthOfLIS(vector<int>& nums)
    {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans,solve(i, nums));
        
        return ans;
        
    }
    
    int solve(int i, vector<int>& nums)
    {
        if(dp[i] != -1)
            return dp[i]; 
        
        int ans = 1;
        for(int j=i+1;j<nums.size();j++)
            if(nums[j] > nums[i])
                ans = max(ans, 1+solve(j, nums));
        
        return dp[i] = ans;
    }
    
    
};