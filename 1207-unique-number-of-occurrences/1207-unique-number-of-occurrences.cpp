class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int,int> umap;
        
        for(auto x: arr)
            umap[x]++;
        
        unordered_set<int> uset;
        
        for(auto x: umap)
        {
            int freq = x.second;
            
            if(uset.find(freq) == uset.end())
                uset.insert(freq);
            
            else
                return false;
        }
        
        return true;
        
    }
};