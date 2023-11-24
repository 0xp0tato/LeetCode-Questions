class Solution {
public:
    int maxCoins(vector<int>& piles)
    {
        int ans = 0;
        int n = piles.size();
        
        sort(piles.begin(), piles.end(), greater<>());
        
        for(auto x: piles)
            cout<<x<<" ";
        
        for(int i=1;i<n;i=i+2)
        {
            if(i >= piles.size())
                break;

            ans += piles[i];
            piles.pop_back();
            
        }
        
        return ans;
        
    }
};