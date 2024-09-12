class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        unordered_map<int, int> freq;
        int ans = 0;
        
        for(char c: allowed)
            freq[c]++;
        
        for(string s: words)
        {
            bool flag = true;
            for(char c: s)
            {
                if(freq.find(c) == freq.end())
                {
                    flag = false;
                    break;
                }
            }
            
            if (flag) ans++;
        }
        
        return ans;
        
    }
};