class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        int n = garbage.size();
        
        int ans = 0;
        
        int lastM = 0;
        int lastP = 0;
        int lastG = 0;
        
        for(int i=0;i<n;i++)
        {
            for(auto x: garbage[i])
            {
                if(x == 'M')
                {
                    ans++;
                    lastM = max(lastM, i);
                }
                
                else if(x == 'P')
                {
                    ans++;
                    lastP = max(lastP, i);
                }
                
                else
                {
                    ans++;
                    lastG = max(lastG, i);
                }
            }
        }
        
        vector<int> prefix(n, 0);
        
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + travel[i-1];
        }
        
        
        ans += prefix[lastM] + prefix[lastG] + prefix[lastP];
        
        return ans;
        
    }
};