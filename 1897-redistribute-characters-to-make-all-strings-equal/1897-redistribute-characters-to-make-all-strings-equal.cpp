class Solution {
public:
    bool makeEqual(vector<string>& words)
    {
        int n = words.size();
        
        if(n == 1)
            return true;
        
        unordered_map<char,int> freq;
        
        for(auto x: words)
            for(auto y: x)
                freq[y]++;
        
        
        for(auto x: freq)
            if(x.second % n != 0)
                return false;
        
        return true;
        
    }
};