class Solution {
public:
    
    static bool cmp(pair<int, string> p1, pair<int, string> p2)
    {
        return p2.first < p1.first;
    }
    
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        int n = names.size();
        vector<pair<int,string>>v;
        
        for(int i=0;i<n;i++)
            v.push_back({heights[i], names[i]});
        
        sort(v.begin(), v.end(), cmp);
        
        vector<string> ans;
        
        for(int i=0;i<n;i++)
            ans.push_back(v[i].second);
        
        return ans;
        
    }
};