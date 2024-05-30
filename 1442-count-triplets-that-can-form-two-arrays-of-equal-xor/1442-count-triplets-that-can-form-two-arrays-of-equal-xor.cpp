class Solution {
public:
    int countTriplets(vector<int>& arr)
    {
        int n = arr.size();
        int ans = 0;
        int x = 0;
        
        for(int i=0;i<n-1;i++)
        {
            x = arr[i];
            for(int j=i+1;j<n;j++)
            {
                x ^= arr[j];
                if(x == 0) ans += j - i;
            }
        }
        
        return ans;
        
    }
};