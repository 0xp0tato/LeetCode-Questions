class Solution {
public:
    bool isPathCrossing(string path)
    {
        int x = 0;
        int y = 0;
        
        unordered_set<string> vis;
        
        vis.insert(to_string(x) + "+" + to_string(y));
        
        for(auto c: path)
        {
            if(c == 'N')
                y++;
            
            else if(c == 'S')
                y--;
            
            else if(c == 'E')
                x++;
            
            else if(c == 'W')
                x--;
            
            if(vis.find(to_string(x) + "+" + to_string(y)) != vis.end())
                return true;
            
            vis.insert(to_string(x) + "+" + to_string(y));
        }
        
        return false;
        
    }
};