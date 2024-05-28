class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums)
    {
        vector<string> s;
        long long ans = 0;
        
        for(int x: nums)
            s.push_back(to_string(x));
        
        int n = s[0].size();
        
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> freq;
            for(int j=0;j<nums.size();j++)
                freq[s[j][i]]++;
            
            
            for(auto x: freq)
                ans += ((nums.size() - x.second) * x.second);
        }
        
        return ans/2;
    }
};