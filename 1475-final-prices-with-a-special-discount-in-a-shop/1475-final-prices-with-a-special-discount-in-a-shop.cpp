class Solution {
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        int n = prices.size();
        stack<pair<int,int>> s;
        
        vector<int> ans(prices.begin(), prices.end());
        
        for(int i=0;i<n;i++)
        {
            if(s.empty() || prices[i] > s.top().first)
                s.push({prices[i], i});
            
            else
            {
                while(!s.empty() and prices[i] <= s.top().first)
                {
                    int idx = s.top().second;
                    
                    ans[idx] = s.top().first - prices[i];
                    
                    s.pop();
                }
                
                s.push({prices[i], i});

            }
        }
        
        return ans;
    }
};