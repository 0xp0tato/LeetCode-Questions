class Solution {
public:
    int minBitFlips(int start, int goal)
    {
        int ans = 0;
        while(start > 0 || goal > 0)
        {
            ans += (start & 1) == (goal & 1) ? 0 : 1;
            start = start>>1;
            goal = goal>>1;
        }
        
        return ans;
        
    }
};