class Solution {
public:
    int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        vector<int> res;
        
        for(int i=0;i<n;i++)
        {
            int s = 0;
            for(int j=i;j<n;j++)
            {
                s = (s + nums[j]) % MOD;
                res.push_back(s);
            }
        }
        
        sort(res.begin(), res.end());
        
        int ans = 0;
        for(int i=left-1;i<right;i++)
            ans = (ans + res[i]) % MOD;
        
        return ans;
        
    }
};