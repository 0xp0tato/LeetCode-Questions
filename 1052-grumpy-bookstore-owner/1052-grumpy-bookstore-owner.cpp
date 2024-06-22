class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int l = 0;
        int r = 0;
        
        int n = grumpy.size();
        
        int ans = 0;
        int window = 0;
        int max_window = 0;
        int g = 0;
        
        for(;r<n;r++)
        {
            if(grumpy[r] == 0) ans += customers[r];
            
            else window += customers[r];
            
            if(r - l + 1 > minutes)
            {
                if(grumpy[l] == 1) window -= customers[l];
                l++;
            }
            
            max_window = max(max_window, window);
        }
        
        return ans + max_window;
        
    }
};