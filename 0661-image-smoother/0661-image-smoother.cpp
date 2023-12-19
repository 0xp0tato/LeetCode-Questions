class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        int m = img.size();
        int n = img[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int res = img[i][j];
                int count = 1;
                
                res += ((j-1 >= 0) ? img[i][j-1] : 0) + 
                    ((i-1 >= 0 and j-1 >= 0) ? img[i-1][j-1] : 0) + 
                    ((i-1 >= 0) ? img[i-1][j] : 0) + 
                    ((i-1 >= 0 and j+1 < n)? img[i-1][j+1] : 0) + 
                    ((j+1 < n) ? img[i][j+1] : 0) + 
                    ((i+1 < m and j+1 < n) ? img[i+1][j+1] : 0) + 
                    ((i+1 < m) ? img[i+1][j] : 0) + 
                    ((i+1 < m and j-1 >= 0) ? img[i+1][j-1] : 0);
                
                count += ((j-1 >= 0) ? 1 : 0) + 
                    ((i-1 >= 0 and j-1 >= 0) ? 1 : 0) + 
                    ((i-1 >= 0) ? 1 : 0) + 
                    ((i-1 >= 0 and j+1 < n) ? 1 : 0) + 
                    ((j+1 < n) ? 1 : 0) + 
                    ((i+1 < m and j+1 < n) ? 1 : 0) + 
                    ((i+1 < m) ? 1 : 0) + 
                    ((i+1 < m and j-1 >= 0) ? 1 : 0);
                
                ans[i][j] = res/count;
            }
        
        return ans;
        
    }
};