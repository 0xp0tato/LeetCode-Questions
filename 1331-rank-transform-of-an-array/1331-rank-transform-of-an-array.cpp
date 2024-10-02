class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        int n = arr.size();
        
        vector<int> ans(n);
        
        map<int, vector<int>> pos;
        
        for(int i=0;i<n;i++)
            pos[arr[i]].push_back(i);
        
        int r = 1;
        for(auto x: pos)
        {
            for(int nn: x.second)
                ans[nn] = r;
            
            r++;
        }
        
        return ans;
    }
};