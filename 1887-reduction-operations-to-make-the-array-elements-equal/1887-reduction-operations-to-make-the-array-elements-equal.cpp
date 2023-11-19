class Solution {
public:
    int reductionOperations(vector<int>& nums)
    {
        map<int,int,greater<int>> freq;
        
        for(auto x: nums)
            freq[x]++;
        
        int ans = 0;
        while(freq.size() > 1)
        {
            int largest = freq.begin()->first;
            int largestfreq = freq.begin()->second;
            
            freq.erase(freq.begin());
            
            ans += largestfreq;
            freq[freq.begin()->first] += largestfreq;
        }
        
        return ans;
    }
};