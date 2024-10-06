class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> s1 = words(sentence1);
        vector<string> s2 = words(sentence2);
        
        if(s1.size() > s2.size())
            swap(s1, s2);
        
        int l1 = 0;
        
        while(l1 < s1.size() and s1[l1] == s2[l1])
            l1++;
        
        int r1 = s1.size()-1;
        int r2 = s2.size()-1;
        
        while(r1 >= l1 and s1[r1] == s2[r2])
        {
            r1--;
            r2--;
        }
        
        return l1 > r1;
        
    }
    
    
    vector<string> words(string &sentence)
    {
        string temp;
        vector<string> res;
        for(char c: sentence)
        {
            if(c == ' ')
            {
                res.push_back(temp);
                temp = "";
            }
            
            else temp += c;
        }
        
        res.push_back(temp);
        
        return res;
    }
};