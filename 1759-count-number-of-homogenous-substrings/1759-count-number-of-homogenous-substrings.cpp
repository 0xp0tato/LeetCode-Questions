class Solution {
public:
    int MOD = 1e9+7;
    int countHomogenous(string s)
    {
        long long int n=1;
        int l = s.size();
        long long int ans = 0;
        
        for(int i=1;i<l;i++)
        {
            if(s[i] == s[i-1])
                n++;
            
            else
            {
                ans += ((n * (n + 1)) / 2)%MOD;
                n=1;
            }
        }
        
        ans += ((n * (n + 1)) / 2)%MOD;
        
        return ans;
    }
};