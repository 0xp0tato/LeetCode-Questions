class Solution {
public:
    bool canArrange(vector<int>& arr, int k)
    {
        unordered_map<int, int> freq;
        
        for(int n: arr)
        {
            int n1 = ((n % k) + k) % k;
            int n2 = (k - n1) % k;
            
            if(freq.find(n2) != freq.end())
            {
                freq[n2]--;
                if(freq[n2] == 0)
                    freq.erase(n2);
            }
            
            else freq[n1]++;
        }
        
        if(freq.find(0) != freq.end() and freq[0] % 2 == 1)
            return false;
        
        return freq.size() == 0;
        
    }
};