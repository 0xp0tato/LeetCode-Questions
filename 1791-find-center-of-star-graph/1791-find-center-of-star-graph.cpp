class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        int c1 = edges[0][0];
        int c2 = edges[0][1];
        
        for(int i=1;i<edges.size();i++)
        {
            if(edges[i][0] == c1 || edges[i][1] == c1) return c1;
            
            if(edges[i][0] == c2 || edges[i][1] == c2) return c2;
        }
        
        return 0;
        
    }
};