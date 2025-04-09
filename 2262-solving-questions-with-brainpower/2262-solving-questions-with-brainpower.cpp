class Solution {
public:
    long long dp[100001];
    long long mostPoints(vector<vector<int>>& questions)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, questions);
    }

    long long solve(int i, vector<vector<int>>& questions)
    {
        if(i >= questions.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        // take
        long long take = questions[i][0] + solve(i + questions[i][1] + 1, questions);

        // not take
        long long notTake = solve(i+1, questions);

        return dp[i] = max(take, notTake);
    }
};