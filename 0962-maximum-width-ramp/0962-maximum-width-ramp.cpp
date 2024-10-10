class Solution {
public:
    int maxWidthRamp(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> mx(nums.begin(), nums.end());
        
        for(int i=n-2;i>=0;i--)
            mx[i] = max(mx[i], mx[i+1]);
        
        int l = 0;
        int r = 0;
        
        int ans = 0;
        
        while(r < n)
        {
            if(nums[l] <= mx[r])
            {
                ans = max(ans, r-l);
                r++;
            }
            
            else
                l++;
        }
        
        return ans;
        
    }
};