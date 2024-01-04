class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int ans = 0;
        unordered_map<int,int> freq;
        
        for(auto x: nums)
            freq[x]++;
        
        for(auto x: freq)
        {
            if(x.second == 1)
                return -1;
            
            else
            {
                ans += x.second / 3;
                if(x.second % 3 > 0)
                    ans++;
            }
        }
        
        return ans;
        
    }
};