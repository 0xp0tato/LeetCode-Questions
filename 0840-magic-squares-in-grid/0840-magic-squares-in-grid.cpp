class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        
        int ans = 0;
        
        for(int i=0;i<r-2;i++)
            for(int j=0;j<c-2;j++)
            {
                int a = grid[i][j];
                int b = grid[i][j+1];
                int c = grid[i][j+2];
                int d = grid[i+1][j];
                int e = grid[i+1][j+1];
                int f = grid[i+1][j+2];
                int g = grid[i+2][j];
                int h = grid[i+2][j+1];
                int k = grid[i+2][j+2];
                
                if(!helper(a,b,c,d,e,f,g,h,k)) continue;
                
                int sum = a + b + c;
                
                if(d + e + f == sum and g + h + k == sum and a + e + k == sum and c + e + g == sum and
                  a + d + g == sum and b + e + h == sum and c + f + k == sum)
                    ans++;
            }
        
        return ans;
        
    }
    
    bool helper(int a,int b,int c,int d,int e,int f,int g,int h,int i)
    {
        if(a < 1 || a > 9 || b < 1 || b > 9 || c < 1 || c > 9 || d < 1 || d > 9 || e < 1 || e > 9 || f < 1 || f > 9 || g < 1 || g > 9 || h < 1 || h > 9 || i < 1 || i > 9) return false;
        
        vector<int> dd = {a,b,c,d,e,f,g,h,i};
        unordered_set<int> uset;
        
        for(int n: dd)
        {
            if(uset.find(n) != uset.end()) return false;
            uset.insert(n);
        }
        
        return true;
    }
};