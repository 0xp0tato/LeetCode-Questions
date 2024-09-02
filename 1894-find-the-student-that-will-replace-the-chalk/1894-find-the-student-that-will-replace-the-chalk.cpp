class Solution {
public:
    int chalkReplacer(vector<int>& c, int k)
    {
        int s = 0;
        int n = c.size();
        for(int num: c)
        {
            s += num;
            if(s > k) break;
        }
        
        k = k % s;
        
        for(int i=0;i<n;i++)
        {
            if(k < c[i]) return i;
            
            k = k - c[i];
        }
        
        return 0;
        
    }
};