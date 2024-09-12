class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        unordered_map<int, int> freq;
        int cnt = 0;
        
        for(char c: allowed)
            freq[c]++;
        
        for(string s: words)
        {
            for(char c: s)
            {
                if(freq.find(c) == freq.end())
                {
                    cnt++;
                    break;
                }
            }
        }
        
        return words.size() - cnt;
        
    }
};