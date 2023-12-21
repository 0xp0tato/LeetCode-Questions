class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        priority_queue<int> pq;
        
        for(auto x: points)
            pq.push(x[0]);
        
        int curr = -1;
        int ans = 0;
        
        while(!pq.empty())
        {
            if(curr < 0)
                curr = pq.top();
            
            else
            {
                ans = max(ans, curr - pq.top());
                curr = pq.top();
            }
            
            pq.pop();
        }
        
        return ans;
    }
};