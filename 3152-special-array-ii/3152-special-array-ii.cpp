class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size();
        vector<int> pref(n, 0);
        
        for(int i=1;i<n;i++)
            pref[i] = (nums[i] % 2 == nums[i-1] % 2) + pref[i-1];
        
        vector<bool> ans;
        
        for(vector<int> x: queries)
            ans.push_back(pref[x[0]] == pref[x[1]]);
        
        return ans;
        
    }
};