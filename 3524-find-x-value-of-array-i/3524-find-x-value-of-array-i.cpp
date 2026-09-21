#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> result(k, 0);
        std::vector<long long> dp(k, 0); // Stores counts of subarrays ending at previous index

        for (int num : nums) {
            std::vector<long long> next_dp(k, 0);
            int mod = num % k;

            // Start a new subarray with just `num`
            next_dp[mod]++;

            // Extend existing subarrays from previous index
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int next_rem = (1LL * r * mod) % k;
                    next_dp[next_rem] += dp[r];
                }
            }

            // Accumulate counts into the final answer
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }

            dp = std::move(next_dp);
        }

        return result;
    }
};