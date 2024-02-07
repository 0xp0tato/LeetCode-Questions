class Solution {
public:
    string frequencySort(string s)
    {
        int n = s.length();
        
        if(n == 1)
            return s;
        
        string ans;
        unordered_map<char, int> freq;
        priority_queue<pair<int,char>> pq;
        
        for(auto x: s)
            freq[x]++;
        
        for(auto x: freq)
            pq.push({x.second, x.first});
        
        while(!pq.empty())
        {
            ans+=string(pq.top().first, pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};