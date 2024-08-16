class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int m = arrays.size();
        int mn = arrays[0][0];
        int mx = arrays[0].back();
        
        int ans = INT_MIN;
        
        for(int i=1;i<m;i++)
        {
            int mni = arrays[i][0];
            int mxi = arrays[i].back();
            ans = max({ans, abs(mx - mni), abs(mxi - mn)});
            
            mx = max(mx, mxi);
            mn = min(mn, mni);
        }
        
        return ans;
        
        
    }
};