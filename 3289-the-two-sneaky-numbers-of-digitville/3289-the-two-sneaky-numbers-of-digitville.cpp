class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums)
    {
        unordered_set<int> s;
        vector<int> ans;
        for(int n: nums)   
        {
            if(s.find(n) != s.end())
            {
                ans.push_back(n);
                if(ans.size() == 2)
                    break;
            }
                
            else
                s.insert(n);
        }
        
        return ans;
    }
};