class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        if(nums.size() == 2)
            return nums;
        
        int x = 0;
        
        for(int i: nums)
            x = x ^ i;
        
        int diff = 1;
        
        while (!(diff & x))
            diff = diff << 1;
        
        int a = 0;
        int b = 0;
        
        for(int i: nums)
        {
            if(diff & i) a = a ^ i;
            
            else b = b ^ i;
        }
        
        return {a,b};
    }
};