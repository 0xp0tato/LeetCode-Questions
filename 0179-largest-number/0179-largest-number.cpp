class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> sn;
        
        for(int n: nums)
            sn.push_back(to_string(n));
        
        sort(sn.begin(), sn.end(), [](const string &a, const string &b)
             {
                 return (a + b) > (b + a);
             });
        
        if(sn[0] == "0")
            return "0";
        
        string ans;
        
        for(string s: sn)
            ans += s;
        
        return ans;
        
    }
};