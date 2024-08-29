class Solution {
public:
    int ans;
    int removeStones(vector<vector<int>>& stones)
    {   
        int n = stones.size();
        ans = n;
        vector<int> parent(n);
        
        for(int i=0;i<n;i++)
            parent[i] = i; // [ 0 , 1 , 2 , 3 , 4 , 5 ]
        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    merge(stones, i, j, parent);
                }
            }
        
        return n - ans;
    }
    
    void merge(vector<vector<int>>&stones, int i, int j, vector<int>& parent)
    {
        // find parents
        int p1 = fp(i, parent);
        int p2 = fp(j, parent);
        
        if(p1 == p2)
            return;
        
        ans--;
        parent[p1] = p2;
    }
    
    int fp(int i, vector<int>& parent)
    {
        while(parent[i] != i) i = parent[i];
        
        return i;
    }
};