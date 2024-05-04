class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        std::ios_base::sync_with_stdio(false);
	    std::cin.tie(nullptr);
        int i = 0;
        int j = people.size() - 1;
        
        sort(people.begin(), people.end());
        
        int ans = 0;
        
        while(i <= j)
        {
            if(people[j] + people[i] <= limit)
            {
                j--;
                i++;
            }
            
            else j--;
            
            ans++;
        }
        
        return ans;
        
    }
};