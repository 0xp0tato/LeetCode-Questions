class Solution {
public:
    long long dividePlayers(vector<int>& skill)
    {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        
        int ts = skill[0] + skill[n-1];
        
        long long ans = 0;
        
        for(int i=0;i<n/2;i++)
        {
            if(skill[i] + skill[n-i-1] != ts)
                return -1;
            
            ans += (skill[i] * skill[n-i-1]);
        }
        
        return ans;
        
    }
};