class Solution {
public:
    vector<int> findArray(vector<int>& pref)
    {
        int n = pref.size();
        vector<int> ans(n);
        
        ans[0] = pref[0];
        int x = ans[0];
        
        for(int i=1;i<n;i++)
        {
            ans[i] = x xor pref[i];
            x = x xor ans[i];
        }
        
        return ans;
        
    }
};