class Solution {
public:
    int compareVersion(string v1, string v2)
    {
        int i = 0;
        int j = 0;
        
        int c1 = 0;
        int c2 = 0;
        
        for(;i<v1.size() || j < v2.size();i++,j++)
        {
            while(i < v1.size() && v1[i] !=  '.')
            {
                c1 = 10 * c1 + (v1[i] - '0');
                i++;
            }
            
            while(j < v2.size() && v2[j] != '.')
            {
                c2 = 10 * c2 + (v2[j] - '0');
                j++;
            }
            
            if(c1 < c2)
               return -1;
            
            if(c1 > c2)
                return 1;
            
            c1 = 0;
            c2 = 0;
        }
        
        return 0;
        
    }
};