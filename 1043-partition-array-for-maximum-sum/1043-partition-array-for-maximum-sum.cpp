class Solution {
public:
    int dp[501];
    int n;
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        memset(dp, -1, sizeof(dp));
        int i = 0;
        n = arr.size();
        int ans = solve(i, arr, k);
        
        return ans;
        
    }
    
    int solve(int i, vector<int>& arr, int k)
    {
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ans = 0;
        int maxi = -1;
        
        for(int j=i ; j<n and j-i+1<=k ; j++)
        {
            maxi = max(maxi, arr[j]);
            ans = max(ans, ((j-i+1)*maxi) + solve(j+1, arr, k));
        }
        
        return dp[i] = ans;
    }
};