class Solution {
public:
    bool isAnagram(string s, string t)
    {   
        unordered_map<char,int> umap1;
        unordered_map<char,int> umap2;
        
        for(auto x: s)
            umap1[x]++;
        
        for(auto x: t)
            umap2[x]++;
        
        if(umap1.size() != umap2.size())
            return false;
        
        for(auto x: umap1)
        {
            if(umap1[x.first] != umap2[x.first])
                return false;
        }
        
        return true;
        
    }
};