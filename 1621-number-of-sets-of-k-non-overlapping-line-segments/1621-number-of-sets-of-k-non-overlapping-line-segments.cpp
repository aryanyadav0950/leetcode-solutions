class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        long long N = n + k - 1;
        long long K = 2 * k;

        // Calculate C(N, K) % MOD using Fermat's Little Theorem
        long long num = 1, den = 1;
        for (long long i = 1; i <= K; ++i) {
            num = (num * (N - K + i)) % MOD;
            den = (den * i) % MOD;
        }

        // Modular Inverse using Binary Exponentiation
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        long long denInverse = power(den, MOD - 2);
        return (num * denInverse) % MOD;
    }
};