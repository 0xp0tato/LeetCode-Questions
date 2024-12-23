class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k)
    {
        int n = nums.size();
        int last = -1e9;
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++)
        {
            int m = max(last + 1, nums[i] - k);
            
            if(m > nums[i] + k) continue;
            
            last = m;
            ans++;
        }
        
        return ans;
    }
};