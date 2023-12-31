class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<int> indx(26, -1);
        
        int ans = -1;
        
        for(int i=0;i<s.size();i++)
        {
            if(indx[s[i]-'a'] == -1)
                indx[s[i]-'a'] = i;
            
            else
            {
                int temp = i - indx[s[i]-'a'] - 1;
                
                ans = max(ans, temp);
            }
        }
        
        return ans;
        
    }
};