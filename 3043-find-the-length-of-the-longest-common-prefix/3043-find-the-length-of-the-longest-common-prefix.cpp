class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_set<int> s;
        
        for(int n: arr1)
        {
            while(n)
            {
                s.insert(n);
                n = n / 10;
            }
        }
        
        int ans = 0;
        
        for(int n: arr2)
        {
            while(n)
            {
                if(s.find(n) != s.end())
                    ans = max(ans, len(n));
                
                n = n / 10;
            }
        }
        
        return ans;
        
    }
    
    int len(int n)
    {
        int l = 0;
        while(n)
        {
            l++;
            n = n / 10;
        }
        
        return l;
    }
};