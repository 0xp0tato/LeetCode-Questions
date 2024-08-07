class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_set<int> minis;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            int mn = *min_element(matrix[i].begin(), matrix[i].end());
            minis.insert(mn);
        }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            int mx = INT_MIN;
            for(int j=0;j<m;j++)
                mx = max(mx, matrix[j][i]);
            
            if(minis.find(mx) != minis.end())
                ans.push_back(mx);
        }
        
        return ans;
        
    }
};