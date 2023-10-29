class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int chances = minutesToTest / minutesToDie;
        
        int ans = 0;
        
        while(pow(chances+1, ans) < buckets)
            ans++;
        
        return ans;
        
    }
};