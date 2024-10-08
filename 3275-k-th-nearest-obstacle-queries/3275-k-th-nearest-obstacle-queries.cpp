class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k)
    {
        vector<int> ans;
        
        priority_queue<int> pq;
        
        for(vector<int> q: queries)
        {
            int x = q[0];
            int y = q[1];
            
            pq.push(abs(x) + abs(y));
            
            if(pq.size() < k)
                ans.push_back(-1);
            
            else
            {
                if(pq.size() > k) pq.pop();
                
                ans.push_back(pq.top());
            }
        }
        
        return ans;
    }
};