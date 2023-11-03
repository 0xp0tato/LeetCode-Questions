class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        stack<int> st;
        vector<string> ans;
        int streamNum = 1;
        
        int i = 0;
        while(i<target.size())
        {
            st.push(streamNum);
            ans.push_back("Push");
            
            streamNum++;
            
            if(st.top() == target[i])
                i++;
            
            else
            {
                st.pop();
                ans.push_back("Pop");
            }
        }
        
        return ans;
        
    }
};