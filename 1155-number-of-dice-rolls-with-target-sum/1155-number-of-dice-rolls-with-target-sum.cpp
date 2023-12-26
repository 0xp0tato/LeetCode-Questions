class Solution {
public:
    long long int MOD = 1e9+7;
    int dp[31][1001];
    int numRollsToTarget(int n, int k, int target)
    {
        memset(dp, -1, sizeof(dp));
        
        long long int ans = solve(n, k, target);
        
        return ans;
    }
    
    long long int solve(int n, int k, int target)
    {
        
        if(target == 0 and n == 0)
            return 1;
        
        if(n <= 0 || target <= 0)
            return 0;
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        long long int ans = 0;
        
        for(int i=1;i<=k;i++)
            ans += solve(n-1, k, target-i);
        
        ans = ans % MOD;
        
        return dp[n][target] = ans;
    }
};