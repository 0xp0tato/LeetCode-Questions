class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        unordered_map<int,int> c2p;
        unordered_map<int,vector<int>> adj;
        
        for(int i=0;i<n;i++)
        {
            int l = leftChild[i];
            int r = rightChild[i];
            
            if(l != -1)
            {
                if(c2p.find(l) != c2p.end())
                    return false;
                
                c2p[l] = i;
                adj[i].push_back(l);
            }
            
            if(r != -1)
            {
                if(c2p.find(r) != c2p.end())
                    return false;
                
                c2p[r] = i;
                adj[i].push_back(r);
            }
        }
        
        int root = -1;
        
        for(int i=0;i<n;i++)
        {
            if(c2p.find(i) == c2p.end())
            {
                if(root == -1)
                    root = i;
                
                else
                    return false;
            }
        }
        
        if(root == -1)
            return false;
        
        unordered_set<int> vis;
        queue<int> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            if(vis.find(q.front()) != vis.end())
                return false;
            
            for(auto x: adj[q.front()])
                q.push(x);
            
            vis.insert(q.front());
            q.pop();
        }
        
        if(vis.size() != n)
            return false;
        
        return true;
        
        
        
    }
};