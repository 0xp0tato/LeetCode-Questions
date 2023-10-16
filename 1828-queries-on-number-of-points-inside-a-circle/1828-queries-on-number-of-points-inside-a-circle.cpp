class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
    {
        vector<int> ans;
        for(auto q: queries)
        {
            //(x – h)^2 + (y – k)^2 = r^2
            int h = q[0];
            int k = q[1];
            int r = q[2];
            
            int count = 0;
            
            for(auto p: points)
            {
                int x = p[0];
                int y = p[1];
                
                if(pow(x-h,2) + pow(y-k,2) <= r*r)
                    count++;
                
            }
            
            ans.push_back(count);
            
        }
        
        return ans;
        
    }
};