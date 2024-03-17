class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int n = intervals.size();
        if(n == 0)
            return {newInterval};
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int istart = intervals[i][0];
            int iend = intervals[i][1];
            
            if(iend < newInterval[0])
                ans.push_back({istart, iend});
            
            else if(newInterval[1] < istart)
            {
                ans.push_back({newInterval[0], newInterval[1]});
                newInterval = intervals[i];
            }
            
            else if(istart <= newInterval[0] || newInterval[1] <= iend)
            {
                newInterval[0] = min(istart, newInterval[0]);
                newInterval[1] = max(iend, newInterval[1]);
            }
        }
        
        ans.push_back(newInterval);
        return ans;
        
    }
};