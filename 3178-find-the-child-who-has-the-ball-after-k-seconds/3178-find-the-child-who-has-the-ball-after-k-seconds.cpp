class Solution {
public:
    int numberOfChild(int n, int k)
    {
        int ans = 0;
        int dir = 1;
        
        while(k--)
        {
            ans+= dir;
            if(ans == n-1 || ans == 0) dir *= -1;
        }
        
        return ans;
    }
};