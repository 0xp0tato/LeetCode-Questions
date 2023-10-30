class Solution {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        vector<int> ans;
        map<int,vector<int>> m;
        
        for(auto x: arr)
        {
            int bits = __builtin_popcount(x);
            m[bits].push_back(x);
        }
        
        for(auto x: m)
        {
            vector<int> temp = x.second;
            sort(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        
        return ans;
        
    }
};