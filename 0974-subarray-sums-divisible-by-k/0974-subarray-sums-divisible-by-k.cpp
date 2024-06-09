class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        
        unordered_map<int, int> freq;
        freq[0] = 1;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            int rem = (sum % k + k) % k;
            if(freq.find(rem) != freq.end())
                ans += freq[rem];
            
            freq[rem]++;
        }
        
        return ans;
        
    }
};

//[-1, 2, 9]
/*

ans = 1
sum = 10

0 -> 1
1 -> 2

*/