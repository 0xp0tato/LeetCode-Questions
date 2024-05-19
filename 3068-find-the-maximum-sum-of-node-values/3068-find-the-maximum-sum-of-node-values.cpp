class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
    {
        int n = nums.size();
        vector<int> delta(n);
        
        for(int i=0;i<n;i++)
            delta[i] = (nums[i] ^ k) - nums[i];
        
        sort(delta.begin(), delta.end(), greater<int>());
        
        long long ans = accumulate(nums.begin(), nums.end(), 0ll);
        
        for(int i=0;i<n;i=i+2)
        {
            if(i == n-1)
                break;
            
            long long sum = (delta[i] + delta[i+1]);
            
            if(sum <= 0)
                break;
            
            ans += sum;
        }
        
        return ans;
        
    }
};