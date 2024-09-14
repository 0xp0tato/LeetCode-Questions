class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        int n = arr.size();
        
        for(int i=1;i<n;i++)
            arr[i] = arr[i] ^ arr[i-1];
        
        vector<int> ans;
        int q = queries.size();
        
        for(int i=0;i<q;i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];
            
            if(u==0)
                ans.push_back(arr[v]);
            
            else ans.push_back(arr[u-1] ^ arr[v]);
        }
        
        return ans;
    }
};