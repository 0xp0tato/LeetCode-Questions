class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int,int> freq;
        
        for(int n: nums1)
            freq[n]++;
        
        vector<int> ans;
        
        for(int n: nums2)
        {
            if(freq.find(n) != freq.end() and freq[n] > 0)
            {
                ans.push_back(n);
                freq[n]--;
            }
        }
        
        return ans;
        
    }
};