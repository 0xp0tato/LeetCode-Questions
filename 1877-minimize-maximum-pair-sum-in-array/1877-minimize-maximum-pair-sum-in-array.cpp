class Solution {
public:
    int minPairSum(vector<int>& nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int i = 0;
        int j = n-1;
        
        int sum = 0;
        while(i < j)
        {
            sum = max(sum, nums[i]+nums[j]);
            i++;
            j--;
        }
        
        return sum;
    }
};