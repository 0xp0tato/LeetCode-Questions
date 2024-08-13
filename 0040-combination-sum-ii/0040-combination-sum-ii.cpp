class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& c, int t)
    {
        n = c.size();
        sort(c.begin(), c.end());
        
        solve(0, {}, c, t);
        
        for(auto x: s)
            ans.push_back(x);
        
        return ans;
        
    }
    
    void solve(int i, vector<int> res, vector<int>& c, int t)
    {
        if(t == 0)
        {
            s.insert(res);
            return;
        }
        
        if(t < 0 || i >= n)
            return;
        
        //take
        res.push_back(c[i]);
        solve(i+1, res, c, t-c[i]);
        
        //not take
        res.pop_back();
        while(i+1 < n and c[i] == c[i+1])
            i++;
        
        solve(i+1, res, c, t);
    }
};