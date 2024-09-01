class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n)
    {
        int s = o.size();
        
        if(m*n != s) return {};
        
        vector<vector<int>> ans;
        int i = 0;
        while(i < s)
        {
            vector<int> temp(o.begin()+i, o.begin()+i+n);
            i+=n;
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};