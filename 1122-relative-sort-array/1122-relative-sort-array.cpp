class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_map<int, int> umap;
        vector<int> ans;
        for(auto x: arr1)
            umap[x]++;
        
        for(auto x: arr2)
        {
            if(umap.find(x)!=umap.end())
            {
                for(int i=0;i<umap[x];i++)
                    ans.push_back(x);
                
                umap[x] = 0;
            }
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto x: umap)
        {
            if(x.second == 0)
                continue;
            
            for(int i=0;i<x.second;i++)
                pq.push(x.first);
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
        
    }
};