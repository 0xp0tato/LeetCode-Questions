class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long int ans = 0;
        int i = 0;
        
        while(k--)
        {
            ans += max(happiness[i] - i, 0);
            i++;
        }
        
        return ans;
        
    }
};