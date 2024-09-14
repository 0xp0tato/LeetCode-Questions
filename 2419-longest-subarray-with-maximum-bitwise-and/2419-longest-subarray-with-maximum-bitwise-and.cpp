class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int l = 0;
        int r = 0;
        int n = nums.size();
        
        int res = 0;
        int ans = 0;
        int cm = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] < cm)
            {
                res = 0;
            }
            
            else if(nums[i] == cm)
            {
                res++;
                ans = max(res, ans);
            }
            
            else
            {
                cm = nums[i];
                res = 1;
                ans = 1;
            }
        }
        
        return ans;
        
    }
};