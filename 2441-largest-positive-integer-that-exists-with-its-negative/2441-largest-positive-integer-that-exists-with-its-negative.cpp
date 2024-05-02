class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        int ans = -1;
        
        unordered_set<int> uset;
        
        for(auto x: nums)
        {
            int to_find = -1 * x;
            if(uset.find(to_find) != uset.end())
                ans = max({ans, to_find, x});
            
            uset.insert(x);
        }
        
        return ans;
        
    }
};