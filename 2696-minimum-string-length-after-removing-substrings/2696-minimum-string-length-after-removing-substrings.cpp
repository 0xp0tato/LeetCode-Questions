class Solution {
public:
    int minLength(string s) {
        vector<char> st;
        
        for(char c: s)
        {
            if(st.size() and ( (c == 'B' and st.back() == 'A') || (c == 'D' and st.back() == 'C') ))
                st.pop_back();
            
            else st.push_back(c);
        }
        
        return st.size();
    }
};