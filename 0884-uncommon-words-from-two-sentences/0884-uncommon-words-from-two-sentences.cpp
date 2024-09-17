class Solution {
public:
    unordered_map<string,int> freq;
    vector<string> uncommonFromSentences(string s1, string s2)
    {   
        w(s1);
        w(s2);
        
        vector<string> ans;
        for(auto x: freq)
            if(x.second == 1)
                ans.push_back(x.first);
        
        return ans;
    }
    
    void w(string s)
    {
        string temp;
        for(char c: s)
        {
            if(c == ' ')
            {
                freq[temp]++;
                temp = "";
            }
            
            else
                temp += c;
        }
        
        if(temp.size() > 0)
            freq[temp]++;
    }
};