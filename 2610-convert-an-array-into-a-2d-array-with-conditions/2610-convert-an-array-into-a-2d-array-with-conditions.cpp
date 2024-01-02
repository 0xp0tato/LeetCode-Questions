class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        int n = nums.size();
        int count = 0;
        
        unordered_set<int> indx;
        
        vector<vector<int>> ans;
        
        while(count < n)
        {
            unordered_set<int> elems;
            for(int i=0;i<nums.size();i++)
            {
                if(indx.find(i) == indx.end() and elems.find(nums[i]) == elems.end())
                {
                    indx.insert(i);
                    elems.insert(nums[i]);
                }
            }
            
            vector<int> temp;
            
            for(auto x: elems)
                temp.push_back(x);
                
            ans.push_back(temp);
            count += temp.size();
        }
        
        return ans;
        
    }
};