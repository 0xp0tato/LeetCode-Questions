class Solution {
public:
    int maxScore(string s)
    {
        int totalOnes = 0;
        
        for(auto x: s)
            if(x == '1')
                totalOnes++;
        
        int zeroes = 0;
        int ans = 0;
        
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i] == '0') zeroes++;
            
            else totalOnes--;
            
            ans = max(ans, zeroes + totalOnes);
        }
        
        return ans;
        
        
        
    }
};