class Solution {
public:
    string largestGoodInteger(string num)
    {
        string ans = "";
        
        for(int i=0;i<num.size()-2;i++)
        {
            if(num[i] == num[i+1] and num[i+1] == num[i+2])
                ans = maximum(ans, num.substr(i,3));
        }
        
        return ans;
        
    }
    
    string maximum(string s1, string s2)
    {
        if(s1 == "")
            return s2;
        
        if(s2[0] > s1[0])
            return s2;
        
        return s1;
    }
};