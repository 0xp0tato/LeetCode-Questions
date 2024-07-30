class Solution {
public:
    int minimumDeletions(string s)
    {
        int ar = 0;
        
        for(char c: s)
            if(c == 'a') ar++;
        
        int ans = INT_MAX;
        int bl = 0;
        for(char c: s)
        {
            if (c == 'a') ar--;
            
            ans = min(ans, ar + bl);
            
            if (c == 'b') bl++;
        }
        
        return ans;
        
    }
};