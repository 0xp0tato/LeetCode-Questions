class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        string ans;
        int m_length = 0;
        
        for(int i=0;i<n;i++)
        {
            int left = i;
            int right = i;
            
            while(left >=0 && right < n && s[left] == s[right])
            {
                if(right - left + 1 > m_length)
                {
                    m_length = right-left+1;
                    ans = s.substr(left, right-left+1);
                }
                
                left--;
                right++;
            }
            
            left = i;
            right = i+1;
            
            while(left >=0 && right < n && s[left] == s[right])
            {
                if(right - left + 1 > m_length)
                {
                    m_length = right-left+1;
                    ans = s.substr(left, right-left+1);
                }
                
                left--;
                right++;
            }
        }
        
        return ans;
    }
};