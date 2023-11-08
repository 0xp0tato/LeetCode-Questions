class Solution {
public:
    
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        long long int xdist = abs(sx-fx);
        long long int ydist = abs(sy-fy);
        
        long long int mintime = min(xdist, ydist) + abs(xdist - ydist);
        
        if(mintime == 0 && t == 1)
            return false;
        
        if(mintime <= t)
            return true;
        
        return false;
    }
};