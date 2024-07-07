class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = 0;
        int rem = 0;
        while(numBottles)
        {
            ans += numBottles; //consume
            rem += numBottles;
            
            numBottles = rem / numExchange;
            rem = rem % numExchange;
        }
        
        return ans;
        
    }
};