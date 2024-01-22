class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans;
        unordered_set<int> missing;
        
        for(int i=1;i<=n;i++)
          missing.insert(i);
        
        for(auto x: nums)
            {
            if(missing.find(x) != missing.end())
                missing.erase(x);
            else
                ans.push_back(x);
            }
        
        ans.push_back(*missing.begin());
        
        return ans;
        
    }
};