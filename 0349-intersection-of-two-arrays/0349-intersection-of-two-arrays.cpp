class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> uset;
        
        for(auto x: nums1)
            uset.insert(x);
        
        unordered_set<int> uset2;
        for(auto x: nums2)
            if(uset.find(x) != uset.end())
                uset2.insert(x);
        
        vector<int> ans(uset2.begin(), uset2.end());
        
        return ans;
        
    }
};