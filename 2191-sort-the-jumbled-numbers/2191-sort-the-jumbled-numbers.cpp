class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums)
    {
        unordered_map<int,int> m;
        
        for(int i=0;i<10;i++)
            m[i] = mapping[i];
        
        vector<pair<int,int>> vp;
        
        for(int n: nums)
            vp.push_back({n, mv(n, m)});
        
        sort(vp.begin(), vp.end(), [&](const pair<int,int> &a, const pair<int,int> &b){
            return a.second < b.second;
        });
        
        vector<int> ans;
        
        for(pair<int,int> p: vp) ans.push_back(p.first);
        
        return ans;
        
    }
    
    int mv(int n, unordered_map<int, int>& m)
    {
        if (n == 0) return m[0];
        
        int mappedValue = 0;
        vector<int> digits;
        
        // Extract digits in reverse order
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        
        // Construct the mapped value using the mapping array
        for (int i = digits.size() - 1; i >= 0; --i) {
            mappedValue = mappedValue * 10 + m[digits[i]];
        }
        
        return mappedValue;
    }
};