#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct State {
        int total_len;
        int cnt[10];
        State() {
            total_len = 1e9;
            fill(cnt, cnt + 10, 0);
        }
    };

    // Compares two states: prefers shorter total length, then lexicographically smaller digit arrangement
    bool is_better(const State& cand, const State& current) {
        if (cand.total_len != current.total_len) {
            return cand.total_len < current.total_len;
        }
        for (int d = 2; d <= 8; ++d) {
            if (cand.cnt[d] != current.cnt[d]) {
                return cand.cnt[d] > current.cnt[d];
            }
        }
        return false;
    }

    void get_factors(int dig, int &f2, int &f3, int &f5, int &f7) {
        f2 = f3 = f5 = f7 = 0;
        if (dig == 2) f2 = 1;
        else if (dig == 3) f3 = 1;
        else if (dig == 4) f2 = 2;
        else if (dig == 5) f5 = 1;
        else if (dig == 6) { f2 = 1; f3 = 1; }
        else if (dig == 7) f7 = 1;
        else if (dig == 8) f2 = 3;
        else if (dig == 9) f3 = 2;
    }

    string build_suffix(const State& st, int rem_c, int rem_d, int target_len) {
        int count5 = rem_c;
        int count7 = rem_d;
        int non_ones = st.total_len + count5 + count7;
        int ones = target_len - non_ones;
        
        string res = "";
        res.append(ones, '1');
        res.append(st.cnt[2], '2');
        res.append(st.cnt[3], '3');
        res.append(st.cnt[4], '4');
        res.append(count5, '5');
        res.append(st.cnt[6], '6');
        res.append(count7, '7');
        res.append(st.cnt[8], '8');
        res.append(st.cnt[9], '9');
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int req_a = 0, req_b = 0, req_c = 0, req_d = 0;
        while (temp % 2 == 0) { req_a++; temp /= 2; }
        while (temp % 3 == 0) { req_b++; temp /= 3; }
        while (temp % 5 == 0) { req_c++; temp /= 5; }
        while (temp % 7 == 0) { req_d++; temp /= 7; }
        
        // If t has prime factors other than 2, 3, 5, 7, it's impossible
        if (temp > 1) return "-1";

        // Precompute DP table for optimal factors of 2 and 3
        vector<vector<State>> dp(51, vector<State>(31));
        dp[0][0].total_len = 0;

        for (int a = 0; a <= 50; ++a) {
            for (int b = 0; b <= 30; ++b) {
                if (dp[a][b].total_len == 1e9) continue;
                for (int d : {2, 3, 4, 6, 8, 9}) {
                    int na = a + (d == 2 || d == 6 ? 1 : (d == 4 ? 2 : (d == 8 ? 3 : 0)));
                    int nb = b + (d == 3 || d == 6 ? 1 : (d == 9 ? 2 : 0));
                    if (na <= 50 && nb <= 30) {
                        State cand = dp[a][b];
                        cand.total_len++;
                        cand.cnt[d]++;
                        if (is_better(cand, dp[na][nb])) {
                            dp[na][nb] = cand;
                        }
                    }
                }
            }
        }

        int N = num.length();
        int first_zero = N;
        for (int i = 0; i < N; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        // Prefix factors precomputation
        vector<int> pref_a(N + 1, 0), pref_b(N + 1, 0), pref_c(N + 1, 0), pref_d(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            int f2, f3, f5, f7;
            get_factors(num[i] - '0', f2, f3, f5, f7);
            pref_a[i + 1] = pref_a[i] + f2;
            pref_b[i + 1] = pref_b[i] + f3;
            pref_c[i + 1] = pref_c[i] + f5;
            pref_d[i + 1] = pref_d[i] + f7;
        }

        // Check if num itself is valid
        if (first_zero == N) {
            if (pref_a[N] >= req_a && pref_b[N] >= req_b && pref_c[N] >= req_c && pref_d[N] >= req_d) {
                return num;
            }
        }

        // Try prefix length i from N-1 down to 0
        for (int i = N - 1; i >= 0; --i) {
            if (i > first_zero) continue;

            int start_d = num[i] - '0' + 1;
            for (int d = start_d; d <= 9; ++d) {
                int f2, f3, f5, f7;
                get_factors(d, f2, f3, f5, f7);

                int rem_a = max(0, req_a - pref_a[i] - f2);
                int rem_b = max(0, req_b - pref_b[i] - f3);
                int rem_c = max(0, req_c - pref_c[i] - f5);
                int rem_d = max(0, req_d - pref_d[i] - f7);

                int min_len = dp[rem_a][rem_b].total_len + rem_c + rem_d;
                if (min_len <= N - 1 - i) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    ans += build_suffix(dp[rem_a][rem_b], rem_c, rem_d, N - 1 - i);
                    return ans;
                }
            }
        }

        // If no solution of length N exists, build solution of length N' > N
        int min_needed = dp[req_a][req_b].total_len + req_c + req_d;
        int target_len = max(N + 1, min_needed);
        return build_suffix(dp[req_a][req_b], req_c, req_d, target_len);
    }
};