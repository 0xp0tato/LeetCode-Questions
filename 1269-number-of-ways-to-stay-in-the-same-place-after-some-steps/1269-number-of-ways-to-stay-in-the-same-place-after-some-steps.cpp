class Solution {
public:
    int MOD = 1e9+7;
    unordered_map<string,int> dp;
    int numWays(int steps, int arrLen)
    {
        int pos = 0;
        
        return solve(pos, steps, arrLen);
        
    }
    
    int solve(int pos, int steps, int arrLen)
    {
        if(pos <  0 || pos >= arrLen)
            return 0;
        
        if(dp.find(to_string(pos) + "/" + to_string(steps)) != dp.end())
            return dp[to_string(pos) + "/" + to_string(steps)];
        
        if(steps == 0)
        {
            if(pos == 0)
                return 1;
            
            return 0;
        }
        
        //move right
        int ans = (solve(pos+1, steps-1, arrLen)) % MOD;
        
        //move left
        ans = (ans + solve(pos-1, steps-1, arrLen))%MOD;
        
        //stay at place
        ans = (ans + solve(pos, steps-1, arrLen))%MOD;
        
        dp[to_string(pos) + "/" + to_string(steps)] = ans;
        
        return ans;
    }
};