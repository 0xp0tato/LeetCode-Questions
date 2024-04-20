#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> findFarmland(vector<vector<int>>& land)
    {
        vector<vector<int>> ans;
        
        m = land.size();
        n = land[0].size();
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(land[i][j] == 1)
                {
                    int x1 = i;
                    int y1 = j;
                    
                    pair<int,int> temp = solve(i,j,land);
                    
                    int x2 = temp.first;
                    int y2 = temp.second;
                    
                    ans.push_back({x1, y1, x2, y2});
                    
                }
        
        return ans;
    }
    
    pair<int, int> solve(int i, int j, vector<vector<int>>& land)
    {
        int x = i;
        int y = j;
        
        if(i+1 < m && land[i+1][j] == 1)
        {
            pair<int,int> temp = solve(i+1, j, land);
            x = max(x,temp.first);
            y = max(y,temp.second);
        }
        
        if(j+1 < n && land[i][j+1] == 1)
        {
            pair<int,int> temp = solve(i, j+1, land);
            x = max(x,temp.first);
            y = max(y,temp.second);
        }
        
        land[i][j] = 2;
        
        return {x, y};
    }
    
};
