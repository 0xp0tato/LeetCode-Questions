class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k)
    {
        priority_queue<pair<int,int>> pq;
        
        vector<int> res(nums.begin(), nums.end());
        
        pq.push({res[0], 0});
        int ans = res[0];
        
        for(int i=1;i<nums.size();i++)
        {
            while(!pq.empty() and i - pq.top().second > k)
                pq.pop();
            
            res[i] = max(res[i], nums[i] + pq.top().first);
            
            pq.push({res[i], i});
            
            
            ans = max(ans, res[i]);
        }
        
        return ans;
        
    }
};