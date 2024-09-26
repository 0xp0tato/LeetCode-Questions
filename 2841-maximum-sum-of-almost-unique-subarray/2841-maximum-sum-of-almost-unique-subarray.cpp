class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k)
    {
        int n = nums.size();
        
        int i = 0;
        int j = 0;
        long long sum = 0;
        
        unordered_map<int,int> freq;
        
        long long ans = 0;
        
        for(int j=0;j<n;j++)
        {
            freq[nums[j]]++;
            sum += nums[j];
            
            if(j-i+1 > k)
            {
                freq[nums[i]]--;
                if(freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            
            if(freq.size() >= m)
                ans = max(ans, sum);
        }
        
        return ans;
    }
};