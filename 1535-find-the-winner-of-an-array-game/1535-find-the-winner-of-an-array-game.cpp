class Solution {
public:
    int getWinner(vector<int>& arr, int k)
    {
        auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
        
        unordered_map<int,int> score;
        
        int n = arr.size();
        int i = 0;
        int j = 1;
        
        while(j < n)
        {
            if(arr[i] > arr[j])
            {
                score[arr[i]]++;
                j++;
                if(score[arr[i]] == k)
                    return arr[i];
            }
            
            else if(arr[j] > arr[i])
            {
                score[arr[j]]++;
                if(score[arr[j]] == k)
                    return arr[j];
                i = j;
                j++;
            }
            
        }
        
        return arr[i];
        
    }
};