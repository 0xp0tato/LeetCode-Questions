class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;
        
        for(auto a:strs)
        {
            string temp = a;
            sort(a.begin(), a.end());
            umap[a].push_back(temp);
        }
        
        for(auto a: umap)
            ans.push_back(a.second);
            
        return ans;
    
    }
};