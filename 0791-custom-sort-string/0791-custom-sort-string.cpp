class Solution {
public:
    string customSortString(string order, string s)
    {
        int i = 0;
        int j = 0;
        
        unordered_map<char,int> freq;
        
        for(auto x: s)
            freq[x]++;
        
        string ans = "";
        
        for(auto x: order)
        {
            ans += string(freq[x], x);
            freq.erase(x);
        }
        
        for(auto x: freq)
        {
            ans += string(x.second, x.first);
        }
        
        return ans;
        
    }
};