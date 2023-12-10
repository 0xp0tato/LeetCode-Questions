class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
        vector<vector<int>> ans;
        
        int col = 0;
        
        while(col < matrix[0].size())
        {
            vector<int> temp;
            
            for(int i=0;i<matrix.size();i++)
                temp.push_back(matrix[i][col]);
            
            ans.push_back(temp);
            col++;
        }
        
        return ans;
        
    }
};