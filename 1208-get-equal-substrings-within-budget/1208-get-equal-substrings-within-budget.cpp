class Solution {
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int l = 0;
        int r = 0;
        int n = s.size();
        
        int ans = 0;
        
        while(r < n)
        {
            maxCost -= abs(s[r] - t[r]);
            
            while(maxCost < 0)
            {
                maxCost += abs(s[l] - t[l]);
                l++;
            }
            
            ans = max(ans, r-l+1);
            r++;
        }
        
        return ans;
    }
};