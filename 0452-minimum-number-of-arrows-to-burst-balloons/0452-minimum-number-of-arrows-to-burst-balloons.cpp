bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
        
        for(auto x: points)
            cout<<x[0]<<"-"<<x[1]<<" ";
        
        cout<<endl;
        
        int ans = 0;
        int curr = 0;
        
        for(int i=0;i<n;i++)
        {
            if(ans == 0 || points[i][0] > curr)
            {
                ans++;
                curr = points[i][1];
            }
        }
        
        return ans;
        
    }
};