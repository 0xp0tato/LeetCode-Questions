class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points)
    {
        int ans = 0;
        
        int sx = points[0][0];
        int sy = points[0][1];
        
        for(int i=1;i<points.size();i++)
        {
            int dx = points[i][0];
            int dy = points[i][1];
            
            ans += max(abs(dx-sx), abs(dy-sy));
            
            sx = dx;
            sy = dy;
        }
        
        return ans;
        
    }
};