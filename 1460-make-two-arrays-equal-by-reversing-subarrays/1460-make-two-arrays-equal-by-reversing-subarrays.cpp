class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr)
    {
        unordered_map<int,int> freq;
        
        for(int n: target)
            freq[n]++;
        
        for(int n: arr)
        {
            if(freq.find(n) == freq.end())
                return false;
            
            freq[n]--;
            
            if(freq[n] == 0)
                freq.erase(n);
        }
        
        if(!freq.empty())
            return false;
        
        return true;
        
    }
};