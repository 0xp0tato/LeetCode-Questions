class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> dis;
        int mini = INT_MAX;

        for(int n: nums)
        {
            mini = min(mini, n);
            dis.insert(n);
        }

        if(mini < k) return -1;

        dis.insert(k);

        return dis.size() - 1;
    }
};