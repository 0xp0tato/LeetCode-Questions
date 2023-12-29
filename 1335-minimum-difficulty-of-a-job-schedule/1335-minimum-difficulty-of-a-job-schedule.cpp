int dp[301][11][1001];
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d)
    {
        memset(dp, -1, sizeof(dp));
        if (d > jobDifficulty.size())
            return -1;
        
        int i = 0;
        int maxi = 0;
        int ans = solve(i, jobDifficulty, d, maxi);
        
        return ans;
        
    }
    
    int solve(int i, vector<int>& jobDifficulty, int d, int maxi)
    {
        if(i == jobDifficulty.size() and d == 0)
            return 0;
        
        if(i == jobDifficulty.size() || d == 0)
            return 1e9;
        
        if(dp[i][d][maxi] != -1)
            return dp[i][d][maxi];
        
        maxi = max(maxi, jobDifficulty[i]);
        
        //divide at i
        int divide = maxi + solve(i+1, jobDifficulty, d-1, 0);
        
        //not divide at i
        int not_divide = solve(i+1, jobDifficulty, d, maxi);
        
        return dp[i][d][maxi] = min(divide, not_divide);
    }
};