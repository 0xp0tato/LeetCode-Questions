class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int> p;
        vector<int> n;
        
        int size = nums.size();
        
        for(auto x: nums)
            x < 0 ? n.push_back(x) : p.push_back(x);
        
        vector<int> ans;
        for(int i=0;i<size/2;i++)
        {
            ans.push_back(p[i]);
            ans.push_back(n[i]);
        }
        
        return ans;
        
    }
};