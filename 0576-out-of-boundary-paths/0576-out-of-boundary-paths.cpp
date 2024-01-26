class Solution {
public:
    int M;
    int N;
    int MOD = 1e9+7;
    int dp[51][51][51];
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        M = m;
        N = n;
        
        int i = startRow;
        int j = startColumn;
        int moves = maxMove;
        
        int ans = solve(i, j, moves);
        
        return ans;
        
    }
    
    int solve(int i, int j, int moves)
    {
        if(moves < 0)
            return 0;
        
        if(i < 0 || i >= M || j < 0 || j >= N)
            return 1;
        
        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];
        
        int left = solve(i, j-1, moves-1) % MOD;
        int right = solve(i, j+1, moves-1) % MOD;
        int up = solve(i-1, j, moves-1) % MOD;
        int down = solve(i+1, j, moves-1) % MOD;
        
        int ans = (((left + right)%MOD + up)%MOD + down) % MOD;
        
        return dp[i][j][moves] = ans;
    }
};