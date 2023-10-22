class Solution {
public:
    int maximumScore(vector<int>& nums, int k)
    {
        int n = nums.size();
        
        int l = k;
        int r = k;
        
        int mini = nums[k];
        int ans = nums[k];
        
        while(l > 0 or r < n-1)
        {
            int left;
            int right;
            
            l > 0 ? left = nums[l-1] : left = 0;
            r < n-1 ? right = nums[r+1] : right = 0;
            
            if(left > right)
            {
                l--;
                mini = min(mini, left);
            }
            
            else
            {
                r++;
                mini = min(mini, right);
            }
            
            ans = max(ans, mini * (r-l+1));
        }
        
        return ans;
        
    }
};