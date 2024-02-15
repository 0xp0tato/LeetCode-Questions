class Solution {
public:
    long long largestPerimeter(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        long long int sum = nums[0] + nums[1];
        long long int ans = 0;
        
        bool flag = false;
        
        for(int i=2;i<n;i++)
        {
            if(sum > nums[i])
            {
                ans = sum + nums[i];
                flag = true;
            }
            
            sum += nums[i];
        }
        
        if(!flag)
            return -1;
        
        return ans;
    }
};