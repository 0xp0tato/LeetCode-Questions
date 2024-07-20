class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum)
    {
        int rows = rowSum.size();
        int cols = colSum.size();
        
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        
        int i = 0;
        int j = 0;
        
        while(i < rows and j < cols)
        {
            int mini = min(rowSum[i], colSum[j]);
            
            ans[i][j] = mini;
            
            rowSum[i] -= mini;
            colSum[j] -= mini;
            
            if(rowSum[i] == 0) i++;
            
            else j++;
        }
        
        return ans;
        
    }
};