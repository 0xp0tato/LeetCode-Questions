class Solution {
public:
    int numTeams(vector<int>& rating)
    {
        int n = rating.size();
        int ans = 0;
        
        for(int i=1;i<n-1;i++)
        {
            int prelarger = 0;
            int postsmaller = 0;
            
            int presmaller = 0;
            int postlarger = 0;
            
            for(int j=0;j<i;j++)
            {
                if(rating[j] < rating[i]) presmaller++;
                
                else if (rating[j] > rating[i]) prelarger++;
            }
            
            for(int j=i+1;j<n;j++)
            {
                if(rating[i] < rating[j]) postlarger++;
                
                else if(rating[i] > rating[j]) postsmaller++;
            }
            
            ans += (prelarger * postsmaller) + (presmaller * postlarger);
        }
        
        return ans;
        
    }
};