class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        int n = score.size();
        vector<string> ans(n);
        
        map<int,int,greater<int>> m;
        
        for(int i=0;i<n;i++)
            m.insert({score[i], i});
        
        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int i = 0;
        
        for(auto x: m)
        {
            int pos = x.second;
            string s;
            
            if(i < rank.size())
                s = rank[i];
            
            else
                s = to_string(i+1);
            
            i++;
            
            ans[pos] = s;
        }
        
        return ans;
    }
};