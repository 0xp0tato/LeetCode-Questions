class Solution {
public:
    int minSwaps(string s)
    {
        stack<char> st;
        
        for(char c: s)
        {
            if(c == ']' and !st.empty() and st.top() == '[')
                st.pop();
            
            else st.push(c);
        }
        
        return ((st.size()/2) + 1)/2;
        
    }
};