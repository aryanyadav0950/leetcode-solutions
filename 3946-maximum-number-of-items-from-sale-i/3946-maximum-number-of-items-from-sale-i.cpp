
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int max_f = 0;
        for (const auto& item : items) {
            max_f = max(max_f, item[0]);
        }

        vector<int> freq(max_f + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> div_count(max_f + 1, 0);
        for (int f = 1; f <= max_f; ++f) {
            for (int m = f; m <= max_f; m += f) {
                div_count[f] += freq[m];
            }
        }

        vector<int> dp(budget + 1, 0);
        int min_price = budget + 1;

        for (const auto& item : items) {
            int f = item[0];
            int p = item[1];
            min_price = min(min_price, p);
            int first_gain = div_count[f];

            for (int b = budget; b >= p; --b) {
                dp[b] = max(dp[b], dp[b - p] + first_gain);
            }
        }

        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            int extra = (budget - b) / min_price;
            ans = max(ans, dp[b] + extra);
        }

        return ans;
    }
};