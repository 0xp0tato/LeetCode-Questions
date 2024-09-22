class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords)
    {
        unordered_set<string> b(bannedWords.begin(), bannedWords.end());
        
        int c = 0;
        for(string s: message)
        {
            if(b.find(s) != b.end())
                c++;
            
            if(c == 2)
                return true;
        }
        
        return false;
        
    }
};