class Solution {
public:
    int buyChoco(vector<int>& prices, int money)
    {
        sort(prices.begin(), prices.end());
        
        int c1 = prices[0];
        int c2 = prices[1];
        
        if(c1 + c2 > money)
            return money;
        
        return money - (c1 + c2);
        
    }
};