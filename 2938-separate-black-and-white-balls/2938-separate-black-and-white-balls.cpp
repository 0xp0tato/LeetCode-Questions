class Solution {
public:
    long long minimumSteps(string s)
    {
        int o = 0;
        int count = 0;
        
        long long ans = 0;
        
        for(char c: s)
        {
            if(c == '1')
                count++;
            
            else ans += count;
        }
        
        return ans;
        
    }
};