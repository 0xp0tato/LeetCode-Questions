class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        vector<string> ans;
        int streamNum = 1;
        
        int i = 0;
        while(i<target.size())
        {
            ans.push_back("Push");
            
            if(streamNum == target[i])
                i++;
            
            else
                ans.push_back("Pop");
            
            streamNum++;
        }
        
        return ans;
        
    }
};