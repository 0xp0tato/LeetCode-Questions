class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
    {
        int m = l.size();

        vector<bool> ans;
        
        for(int i=0;i<m;i++)
        {
            int left = l[i];
            int right = r[i];
            
            vector<int> temp;
            
            for(int j=left;j<=right;j++)
                temp.push_back(nums[j]);
            
            sort(temp.begin(), temp.end());
            
            int diff = temp[1] - temp[0];
            
            bool res = true;
            
            for(int j=2; j<temp.size(); j++)
            {
                if(temp[j] - temp[j-1] != diff)
                {
                    res = false;
                    break;
                }
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};