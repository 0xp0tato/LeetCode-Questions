class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& co)
    {
        vector<vector<long long>> mat(26, vector<long long>(26, INT_MAX));
        
        for(int i=0;i<o.size();i++)
            mat[o[i] - 'a'][c[i] - 'a'] = min(mat[o[i] - 'a'][c[i] - 'a'], (long long)co[i]);
        
        for(int i=0;i<26;i++)
            mat[i][i] = 0;
        
        // floyd warshall
        
        for(int k=0;k<26;k++)
            for(int i=0;i<26;i++)
                for(int j=0;j<26;j++)
                {
                    if(mat[i][k] == INT_MAX or mat[k][j] == INT_MAX) continue;
                    
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
        
        int n = s.size();
        
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            if(mat[s[i] - 'a'][t[i] - 'a'] == INT_MAX) return -1;
            ans += mat[s[i] - 'a'][t[i] - 'a'];
        }
        
        return ans;
        
    }
};