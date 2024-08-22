class Solution {
public:
    int findComplement(int num)
    {
        int ans = 0;
        int i = 0;
        
        while(num)
        {
            int bit = ((num % 2) - 1) * -1;
            
            ans += bit * pow(2, i);
            i++;
            num = num / 2;
        }
        
        return ans;
        
    }
};