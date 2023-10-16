class Solution {
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.size();
        
        int l=0;
        int r = 0;
        string ans = "";
        int cnt = 0;
        
        while(r < n)
        {
            if(s[r] == '1')
                cnt++;
            
            while(l < n && cnt == k)
            {
                string temp = s.substr(l, r-l+1);
                if(ans.size() == 0 || temp.size() < ans.size())
                    ans = temp;
                
                else if(ans.size() == temp.size())
                    ans = min(ans, temp);
                
                if(s[l] == '1')
                    cnt--;
                
                l++;
            }
            
            r++;
        }
        
        return ans;
    }
};