class Solution {
public:
    int maxDepth(string s)
    {
        int ans = 0;
        
        stack<char> st;
        
        int count = 0;
        for(auto x: s)
        {
            if(x == '(')
            {
                st.push(x);
                count++;
            }
            
            else if(x == ')')
            {
                st.pop();
                count--;
            }
            
            ans = max(ans, count);
        }
        
        return ans;
        
    }
};