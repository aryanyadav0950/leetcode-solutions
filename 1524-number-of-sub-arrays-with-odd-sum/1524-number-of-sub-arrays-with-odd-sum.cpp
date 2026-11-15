class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0;
        long long evenCount = 1;
        long long prefixSum = 0;
        long long total = 0;
        const int MOD = 1e9 + 7;

        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2 != 0) {
                total = (total + evenCount) % MOD;
                oddCount++;
            } else {
                total = (total + oddCount) % MOD;
                evenCount++;
            }
        }

        return total;
    }
};