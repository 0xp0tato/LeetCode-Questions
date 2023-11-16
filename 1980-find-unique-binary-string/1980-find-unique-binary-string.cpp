class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        int n = nums.size();
        
        unordered_set<string> ele;
        
        for(auto x: nums)
            ele.insert(x);
        
        for(int i=0;i<10e5;i++)
            if(ele.find(convert2(i,n)) == ele.end())
                return convert2(i,n);
        
        return "0";
        
    }
    
    string convert2(int i, int n)
    {
        string ans;
        
        while(i){
            ans += to_string(i%2);
            i=i/2;
        }

        while(ans.size() != n)
            ans += "0";
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    
};