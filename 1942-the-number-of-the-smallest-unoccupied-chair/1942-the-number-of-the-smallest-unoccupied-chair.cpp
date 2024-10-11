class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend)
    {
        int n = times.size();
        for(int i=0;i<n;i++)
            times[i].push_back(i);
        
        sort(times.begin(), times.end());
        
        priority_queue<int, vector<int>, greater<int>> available_seats;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> used_seats;
        
        for(int i=0;i<n;i++)
            available_seats.push(i);
        
        for(int i=0;i<n;i++)
        {
            int a = times[i][0];
            int l = times[i][1];
            int idx = times[i][2];
            
            while(!used_seats.empty() && used_seats.top().first <= a)
            {
                auto [l, c] = used_seats.top();
                used_seats.pop();
                available_seats.push(c);
            }
            
            int chair = available_seats.top();
            available_seats.pop();
            
            used_seats.push({l, chair});
            
            if(idx == targetFriend)
                return chair;
        }
        
        return 0;
        
    }
};