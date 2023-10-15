class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> umap;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
            umap[nums[i]] = i;
        
        for(int i=0;i<nums.size();i++)
            if(umap[target-nums[i]] && umap[target-nums[i]] != i)
            {
                ans.push_back(i);
                ans.push_back(umap[target-nums[i]]);
                break;
            }
        
        return ans;
    }
};