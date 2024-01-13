class Solution {
public:
    int minSteps(string s, string t)
    {
        unordered_map<char,int> s_freq;
        
        for(auto x: s)
            s_freq[x]++;
        
        int ans = 0;
        
        for(auto x: t)
        {
            if(s_freq.find(x) == s_freq.end())
                ans++;
            
            else
            {
                s_freq[x]--;
                if(s_freq[x] == 0)
                    s_freq.erase(x);
            }
        }
        
        return ans;
        
    }
};