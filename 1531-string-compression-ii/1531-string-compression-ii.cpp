int dp[101][27][101][101];

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        memset(dp, -1, sizeof(dp));
        int i = 0;
        int pc = 26;
        int freq = 0;
        
        int ans = solve(s, i, pc, freq, k);
        
        return ans;
    }
    
    int solve(string &s, int i, int pc, int freq, int k)
    {
        
        if(k < 0)
            return INT_MAX;
        
        if(i >= s.size())
            return 0;
        
        if(dp[i][pc][freq][k] != -1)
            return dp[i][pc][freq][k];
        
        
        //delete ith character
        
        int d = solve(s, i+1, pc, freq, k-1);
        
        //keep the ith character
        
        int ke;
        
        if(s[i]-'a' != pc)
            ke = 1 + solve(s, i+1, s[i]-'a', 1, k);
        
        else
        {
            int add = 0;
            if(freq == 1 || freq == 9 || freq == 99)
                add++;
            
            ke = add + solve(s, i+1, pc, freq+1, k);
        }
        
        return dp[i][pc][freq][k] = min(d, ke);
    }
};