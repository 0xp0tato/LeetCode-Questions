class RandomizedSet {
private:
    vector<int> v;
    unordered_map<int,int> umap;
    
public:
    RandomizedSet() {
    }
    
    bool insert(int val)
    {
        if(umap.find(val) == umap.end())
        {
            v.push_back(val);
            umap[val] = v.size() - 1;
            return true;
        }
        
        else return false;
        
    }
    
    bool remove(int val)
    {
        if(umap.find(val) != umap.end())
        {
            int size = v.size();
            int idx = umap[val];
            
            swap(umap[v[idx]], umap[v[size-1]]);
            swap(v[idx], v[size-1]);
            
            umap.erase(v[size-1]);
            v.pop_back();
            
            return true;
            
        }
        
        else return false;
        
    }
    
    int getRandom()
    {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */