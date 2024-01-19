class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int option1 = j-1 >= 0 ? matrix[i-1][j-1] : INT_MAX;
                int option2 = matrix[i-1][j];
                int option3 = j+1 < n ? matrix[i-1][j+1] : INT_MAX;
                
                // cout<<matrix[i][j]<<"->";
                matrix[i][j] = matrix[i][j] + min({option1, option2, option3});
                // cout<<matrix[i][j]<<endl;
            }
        }
        
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
        
    }
    
};