class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.size()-1;
        int j = t.size()-1;
        
        int S = 0;
        int T = 0;
        
        while(true)
        {
            while(i>= 0 and (s[i] == '#' || S))
            {
                if(s[i] == '#') S++;
                
                else S--;
                
                i--;
            }
            
            while(j>=0 and (t[j] == '#' || T))
            {
                if(t[j] == '#') T++;
                
                else T--;
                
                j--;
            }
            
            if(i >= 0 and j >= 0 and s[i] == t[j])
                i--,j--;
            
            else break;
        }
        
        if(i == -1 and j == -1)
            return true;
        
        return false;
        
    }
};