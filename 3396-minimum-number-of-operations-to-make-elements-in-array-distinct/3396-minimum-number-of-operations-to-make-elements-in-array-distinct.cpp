class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        unordered_map<int, int> umap;
        int li = -1;
        
        for(int i=0;i<nums.size();i++)
        {
            
            if(umap.find(nums[i]) != umap.end())
                li = max(li, umap[nums[i]]);
            
            umap[nums[i]] = i;
        }
        
//         for(auto x: umap)
//             cout<<x.first<<"->"<<x.second<<endl;
        
//         cout<<li;
        
        int ans = li > -1 ? (li / 3) + 1 : 0;
        
        return ans;
        
    }
};