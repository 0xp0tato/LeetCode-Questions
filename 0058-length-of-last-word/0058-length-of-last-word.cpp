class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size();
        bool flag = false;
        int ans = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(isalpha(s[i]))
            {
                flag = true;
                ans++;
            }
            
            else if(s[i] == ' ' && flag)
                return ans;
        }
        
        return ans;
        
    }
};