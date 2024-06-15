class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        vector<pair<int,int>> sorted;
        int n = profits.size();
        
        for(int i=0;i<n;i++)
            sorted.push_back({capital[i], profits[i]});
        
        sort(sorted.begin(), sorted.end());
        
        priority_queue<int> pq;
        
        int i = 0;
        
        while(k--)
        {
            while(i < n && sorted[i].first <= w)
            {
                pq.push(sorted[i].second);
                i++;
            }
            
            if(pq.empty())
                break;
            
            w += pq.top();
            pq.pop();
        }
        
        return w;
        
    }
};