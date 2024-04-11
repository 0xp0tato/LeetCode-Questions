class Solution {
public:
    string removeKdigits(string num, int k)
    {
        stack<char> s;
        
        for(auto &x: num)
        {
            if(s.empty() || x > s.top())
                s.push(x);
            
            else
            {
                while(!s.empty() and x < s.top() and k)
                {
                    s.pop();
                    k--;
                }
                
                s.push(x);
            }
        }
        
        string res;
        
        while(!s.empty())
        {
            if(k)
                k--;
            
            else
                res += s.top();
            
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        
        int i = 0;
        
        while(res[i] == '0')
            i++;
        
        res =  res.substr(i);
        
        if(res == "")
            return "0";
        
        return res;
        
    }
};