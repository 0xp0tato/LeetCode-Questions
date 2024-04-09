class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k)
    {
        int t_count = tickets[k];
        
        int ans = 0;
        
        for(int i=0;i<tickets.size();i++)
        {
            if(i <= k)
                ans += min(tickets[i], t_count);
            
            else ans += min(tickets[i], t_count - 1);
        }
        
        return ans;
        
    }
};