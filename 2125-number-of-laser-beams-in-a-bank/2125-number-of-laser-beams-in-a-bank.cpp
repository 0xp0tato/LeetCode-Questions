class Solution {
public:
    int numberOfBeams(vector<string>& bank)
    {
        vector<int> floors;
        
        for(auto x: bank)
        {
            int count = 0;
            for(auto y: x)
                if(y == '1')
                    count++;
            
            if(count)
                floors.push_back(count);
        }
        
        if(floors.size() <= 1)
            return 0;
        
        int ans = 0;
        for(int i=1;i<floors.size();i++)
            ans += floors[i] * floors[i-1];
        
        return ans;
        
    }
};