class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2)
    {
        memset(dp, -1, sizeof(dp));
        int i = 0;
        int j = 0;
        
        int ans = solve(i,j,text1,text2);
        
        return ans;
        
    }
    
    int solve(int i, int j, string& text1, string& text2)
    {
        if(i >= text1.size() || j >= text2.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = (text1[i] == text2[j]);
        
        int o1 = solve(i+1, j, text1, text2);
        int o2 = solve(i, j+1, text1, text2);
        int o3 = solve(i+1, j+1, text1, text2);
        
        ans = max({o1,o2,o3 + ans});
        
        return dp[i][j] = ans;
    }
};