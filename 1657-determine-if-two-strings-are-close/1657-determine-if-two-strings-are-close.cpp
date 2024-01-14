class Solution {
public:
    bool closeStrings(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        
        if(n != m)
            return false;
        
        unordered_map<char, int> freq1;
        unordered_map<int, int> freq11;
        
        unordered_map<char, int> freq2;
        unordered_map<int, int> freq21;
        
        for(auto x: word1)
            freq1[x]++;
        
        for(auto x: word2)
            freq2[x]++;
        
        for(auto x: freq1)
            if(freq2.find(x.first) == freq2.end())
                return false;
        
        for(auto x: freq1)
            freq11[x.second]++;
        
        for(auto x: freq2)
            freq21[x.second]++;
        
        return freq11 == freq21;
        
    }
};