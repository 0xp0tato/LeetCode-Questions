class Solution {
public:
    unordered_map<string, char> umap;
    int dp[110];
    int numDecodings(string s)
    {
        memset(dp, -1, sizeof(dp));
        
        for(int i=65;i<=90;i++)
            umap[to_string(i-64)] = (char)i;
        
        int ans = solve(0,s);
        
        return ans;
        
    }
    
    int solve(int idx, string s)
    {
        if(idx > s.length())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        if(idx == s.length())
            return 1;
        
        string temp1 = s.substr(idx, 1);
        string temp2 = s.substr(idx, 2);
        
        int ans = 0;
        
        ans = (umap.find(temp1) != umap.end() ? solve(idx + 1, s) : 0) + (umap.find(temp2) != umap.end() ? solve(idx + 2, s) : 0);
        
        return dp[idx] = ans;
    }
};