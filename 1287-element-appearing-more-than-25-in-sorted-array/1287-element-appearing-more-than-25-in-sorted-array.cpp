class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        int n = arr.size();
        
        n = n * 0.25;
        
        int count = 0;
        int curr = -1;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] == curr)
                count++;
            
            else
            {
                count = 1;
                curr = arr[i];
            }
            
            if(count > n)
                return arr[i];
                
        }
        
        return 0;
        
    }
};