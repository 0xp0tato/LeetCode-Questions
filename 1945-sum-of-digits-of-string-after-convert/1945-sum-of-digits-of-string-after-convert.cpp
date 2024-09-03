class Solution {
public:
    int getLucky(string s, int k)
    {
        int ans = 0;
        
        for(char c: s)
        {
            int s = (c - 'a' + 1);
            while(s)
            {
                ans += s % 10;
                s = s / 10;
            }
        }
        
        k--;
        
        while(k--)
        {
            int temp = ans;
            ans = 0;
            
            while(temp)
            {
                ans += temp % 10;
                temp /= 10;
            }
        }
        
        return ans;
    }
};