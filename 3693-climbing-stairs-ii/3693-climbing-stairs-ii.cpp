class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);
        
        for (int j = 1; j <= n; ++j) {
            int minCost = INT_MAX;
            for (int k = 1; k <= 3; ++k) {
                if (j - k >= 0) {
                    minCost = min(minCost, dp[j - k] + costs[j - 1] + k * k);
                }
            }
            dp[j] = minCost;
        }
        
        return dp[n];
    }
};