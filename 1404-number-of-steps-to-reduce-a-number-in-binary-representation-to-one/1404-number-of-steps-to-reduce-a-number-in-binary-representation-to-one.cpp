class Solution {
public:
    int numSteps(string s)
    {
        int n = s.size();
        
        int ans = 0;
        int carry = 0;
        
        for(int i=n-1;i>0;i--)
        {
            if(((s[i] - '0') + carry) % 2 == 1)
            {
                ans += 2;
                carry = 1;
            }
            
            else ans++;
        }
        
        return ans + carry;
        
    }
};