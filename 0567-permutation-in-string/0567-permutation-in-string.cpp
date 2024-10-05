class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int s1s = s1.size();
        
        vector<int> s1f(26, 0);
        
        for(char c: s1)
            s1f[c-'a']++;
        
        int l=0;
        int r=0;
        
        int s2s = s2.size();
        
        vector<int> s2f(26, 0);
        
        for(r=0;r<s2s;r++)
        {
            s2f[s2[r]-'a']++;
            
            while(r-l+1 > s1s)
            {
                s2f[s2[l]-'a']--;
                l++;
            }
            
            if(r-l+1 == s1s && s1f == s2f)
                return true;
        }
        
        return false;
    }
};