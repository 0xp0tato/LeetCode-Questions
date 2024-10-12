class Solution {
public:
    int minGroups(vector<vector<int>>& intervals)
    {
        vector<int> s;
        vector<int> e;
        
        for(vector<int> n: intervals)
        {
            s.push_back(n[0]);
            e.push_back(n[1]);
        }
        
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        
        int i = 0;
        int j = 0;
        
        int ans = 0;
        
        while(i < intervals.size())
        {
            if(s[i] <= e[j])
                i++;
            
            else j++;
            
            ans = max(ans, i-j);
        }
        
        return ans;
        
    }
};