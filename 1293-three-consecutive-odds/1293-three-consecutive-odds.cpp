class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr)
    {
        int n = arr.size();
        for(int i=0;i<n;i++)
            if(arr[i] % 2 == 1)
            {
                if(i+1 < n and i+2 < n and arr[i+1] % 2 == 1 and arr[i+2] % 2 == 1)
                    return true;
            }
        
        return false;
        
    }
};