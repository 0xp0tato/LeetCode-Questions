class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();
        
        long long int ans = 0;
        
        unordered_map<long, long> umap[n];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
            {
                long diff = (long)nums[j] - nums[i];
                
                int temp = 0;
                if(umap[j].find(diff) != umap[j].end())
                    temp = umap[j][diff];
                
                umap[i][diff] += temp + 1;
                
                ans += temp;
            }
        
        return ans;
        
    }
};