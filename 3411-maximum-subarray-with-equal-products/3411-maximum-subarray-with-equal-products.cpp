class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int max_len = 1;
        long long max_lcm_limit = 2520;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long current_gcd = 0;
            long long current_lcm = 1;

            for (int j = i; j < n; ++j) {
                long long val = nums[j];
                
                if (prod > max_lcm_limit * max_lcm_limit) {
                    break;
                }
                
                prod *= val;
                current_gcd = (j == i) ? val : gcd(current_gcd, val);
                current_lcm = (j == i) ? val : lcm(current_lcm, val);

                if (prod == current_lcm * current_gcd) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
    }
};