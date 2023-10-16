class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> triangle{{1},{1,1}};
        
        if(rowIndex <= 1)
            return triangle[rowIndex];
        
        for(int i=2;i<=rowIndex;i++)
        {
            vector<int> temp(i+1, 0);
            for(int j=0;j<i+1;j++)
            {
                if(j == 0 || j == i)
                    temp[j] = 1;
                
                else
                    temp[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
            triangle.push_back(temp);
        }
        
        return triangle[rowIndex];
        
    }
};