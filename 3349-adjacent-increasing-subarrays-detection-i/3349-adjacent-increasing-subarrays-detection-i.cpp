class Solution {
public:
    int n;
    bool hasIncreasingSubarrays(vector<int>& nums, int k)
    {
        n = nums.size();
        int count = 0;
        
        for(int i=0;i<n-k;i++)
        {
            int a = i;
            int b = a+k;
            
            if(count == 0 or (nums[a] > nums[a-1] and nums[b] > nums[b-1]))
            {
                count++;
                if(count == k)
                    return true;
            }
            
            else count = 1;
        }
        
        if(count == k)
            return true;
        
        return false;
    }
};