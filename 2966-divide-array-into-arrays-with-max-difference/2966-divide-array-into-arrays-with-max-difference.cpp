class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i=i+3)
        {
            int f = nums[i];
            int s = nums[i+1];
            int t = nums[i+2];
            
            if(s-f <= k and t-s <= k and t-f <= k)
                ans.push_back({f,s,t});
            
            else return {};
        }
        
        return ans;
        
    }
};