class Solution {
public:
    int n;
    int dp[100][100];
    int findRotateSteps(string ring, string key)
    {
        memset(dp, -1, sizeof(dp));
        int r = 0;
        int k = 0;
        
        n = ring.size();
        
        int ans = solve(r,k,ring,key);
        
        return ans;
        
    }
    
    int solve(int r, int k, string ring, string key)
    {   
        if(k == key.size())
            return 0;
        
        if(dp[r][k] != -1) return dp[r][k];
        
        int ans = 1e9;
        
        for(int i=0;i<n;i++)
        {
            if(ring[i] == key[k])
            {
                int mini = min(abs(r-i), n-abs(r-i));
                
                ans = min(ans, mini + 1 + solve(i, k+1, ring, key));
            }
        }
        
        return dp[r][k] = ans;
    }
};