class Solution {
public:
    int minimumPushes(string word)
    {
        unordered_map<char,int> freq;
        
        for(char c: word) freq[c]++;
        
        map<int, vector<char>, greater<int>> desc;
        
        for(auto x: freq)
        {
            int f = x.second;
            char w = x.first;
            
            desc[f].push_back(w);
        }
        
        int k = 8;
        int ans = 0;
        int t = 1;
        
        for(auto x: desc)
        {
            vector<char> v = x.second;
            int fr = x.first;
            
            for(int i=0;i<v.size();i++)
            {
                ans += fr * t;
                k--;
                
                if(k == 0)
                {
                    k = 8;
                    t++;
                }
            }
        }
        
        return ans;
        
    }
};