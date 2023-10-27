class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        stack<pair<int,int>> st;
        
        vector<int> ls(n);
        vector<int> rs(n);
        
        st.push({0,-1});
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();
                
            if(st.empty())
                st.push({0,-1});
            
            ls[i] = st.top().second;
            
            st.push({heights[i], i});
        }
        
        while(!st.empty())
            st.pop();
        
        st.push({0,n});
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();
            
            if(st.empty())
                st.push({0,n});
            
            rs[i] = st.top().second;
            
            st.push({heights[i], i});
        }
        
//         for(auto x: ls)
//             cout<<x<<" ";
        
//         cout<<endl;
        
//         for(auto x: rs)
//             cout<<x<<" ";
        
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans, (rs[i] - ls[i] - 1) * heights[i]);
        
        return ans;
        
    }
};