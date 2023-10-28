class Solution {
public:
    int MOD = 1e9+7;
    int dp[26][100000];
    int countVowelPermutation(int n)
    {
        memset(dp, -1, sizeof(dp));
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        
        long long int ans = 0;
        for(auto x: v)
            ans += solve(x, n-1) % MOD;
        
        return ans % MOD;
    }
    
    long long int solve(char c, int n)
    {
        if(n == 0)
            return 1;
        
        if(dp[c-'a'][n] != -1)
            return dp[c-'a'][n];
        
        long long int ans = 0;
        if(c == 'a')
            ans = (solve('e', n-1)) % MOD;
        
        else if(c == 'e')
            ans = (solve('a', n-1) + solve('i', n-1)) % MOD;
        
        else if(c == 'i')
            ans = (solve('a', n-1) + solve('e', n-1) + solve('o', n-1) + solve('u', n-1)) % MOD;
        
        else if(c == 'o')
            ans = (solve('i', n-1) + solve('u', n-1)) % MOD;
        
        else if(c == 'u')
            ans = (solve('a', n-1)) % MOD;
        
        return dp[c-'a'][n] = ans % MOD;
    }
    
};