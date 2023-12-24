class Solution {
public:
    int minOperations(string s)
    {
        int n = s.size();
        
        int count1 = 0;
        int count2 = 0;
        
        //starts with 0
        
        for(int i=0;i<n;i++)
        {
            if(i % 2 == 0 and s[i] == '1')
                count1++;
            
            else if(i % 2 == 1 and s[i] == '0')
                count1++;
        }
        
        //starts with 1
        
        for(int i=0;i<n;i++)
        {
            if(i % 2 == 0 and s[i] == '0')
                count2++;
            
            else if(i % 2 == 1 and s[i] == '1')
                count2++;
        }
        
        return min(count1, count2);
        
    }
};