class Solution {
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        int n = arr.size();
        
        stack<int> st;
        
        int NSL[n];
        int NSR[n];
        
        //next smallest on left
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            
            st.empty() ? NSL[i] = -1 : NSL[i] = st.top();
            
            st.push(i);
        }
        
        st = stack<int>();
        //next smallest on right
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()] > arr[i])
                st.pop();
            
            st.empty() ? NSR[i] = n : NSR[i] = st.top();
            
            st.push(i);
        }
        
        long long int ans = 0;
        int MOD = 1e9+7;
        
        for(int i=0;i<n;i++)
        {
            long long int left = i - NSL[i];
            long long int right = NSR[i] - i;
            
            long long int prod = (left * right * arr[i]) % MOD;
            
            ans = (ans + prod) % MOD;
        }
        
        return ans;
        
    }
};