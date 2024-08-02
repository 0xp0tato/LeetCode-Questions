class Solution {
public:
    int minSwaps(vector<int>& nums)
    {
        int n = nums.size();
        
        int ws = 0;
        
        for(int x: nums)
            if (x == 1) ws++;
        
        int l = 0;
        int r = 0;
        int ans = ws;
        int c1 = 0;
        
        while(r < 2 * n)
        {
            if(nums[r % n] == 1)
                c1++;
            
            if(r - l + 1 > ws)
            {
                if(nums[l % n] == 1)
                    c1--;
                l++;
            }
            
            if(r - l + 1 == ws)
                ans = min(ans, ws - c1);
            
            r++;
        }
        
        return ans;
        
    }
};