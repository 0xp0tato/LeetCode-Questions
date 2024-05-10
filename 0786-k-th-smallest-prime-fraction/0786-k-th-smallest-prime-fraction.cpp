class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
            pq.push({-1.0 * arr[i] / arr[n-1], {i, n - 1}});
        
        while (--k > 0) {
            pair<int, int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0 * arr[cur.first] / arr[cur.second], 
                    {cur.first, cur.second}});
        }
        
        pair<int, int> result = pq.top().second;
        return {arr[result.first], arr[result.second]};
    }
};