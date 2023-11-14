class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<pair<int,int>>v (26, {INT_MAX,INT_MIN});
        
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a'].first = min(i, v[s[i]-'a'].first);
            v[s[i]-'a'].second = max(i, v[s[i]-'a'].second);
        }
        
        unordered_set<char> vis;
        int ans = 0;
        
        for(auto x: s)
        {
            if(vis.find(x) != vis.end())
                continue;
            
            vis.insert(x);
            
            int left = v[x-'a'].first;
            int right = v[x-'a'].second;
            
            unordered_set<char> uniq;
            
            for(int j=left+1;j<right;j++)
                uniq.insert(s[j]);
            
            ans += uniq.size();
        }
        
        return ans;
    }
};