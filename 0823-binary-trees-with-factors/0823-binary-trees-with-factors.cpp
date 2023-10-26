class Solution {
public:
    unordered_map<int,long long int> ways;
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        
        for(auto x: arr)
            ways[x]++;
        
        int n = arr.size();
        for(int i=1;i<n;i++)
            solve(i, arr);
        
        int ans = 0;
        for(auto x: ways)
        {
            ans+=x.second;
            ans = ans % MOD;
        }
        
        return ans;
        
    }
    
    void solve(int i, vector<int>& arr)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] % arr[j] == 0)
            {
                int num2find = arr[i] / arr[j];
                if(ways.find(num2find) != ways.end())
                {
                    ways[arr[i]] += (ways[arr[j]] * ways[num2find]) % MOD;
                    ways[arr[i]] = ways[arr[i]] % MOD;
                }
            }
        }
        
    }
};