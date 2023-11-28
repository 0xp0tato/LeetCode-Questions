class Solution {
public:
    int MOD = 1e9+7;
    int numberOfWays(string corridor)
    {
        vector<int> indexes;
        
        for(int i=0;i<corridor.size();i++)
            if(corridor[i] == 'S')
                indexes.push_back(i);
        
        if(indexes.size() == 0 || indexes.size() % 2 != 0)
            return 0;
        
        long long int ans = 1;
        
        for(int i=2;i<indexes.size();i=i+2)
            ans = (ans * (indexes[i] - indexes[i-1]))%MOD;
        
        return ans;
        
    }
};