class Solution {
public:
    string destCity(vector<vector<string>>& paths)
    {
        unordered_set<string> sources;
        unordered_set<string> dest;
        
        for(auto x: paths)
        {
            sources.insert(x[0]);
            dest.insert(x[1]);
        }
        
        for(auto x: dest)
        {
            if(sources.find(x) == sources.end())
                return x;
        }
        
        return "";
        
    }
};