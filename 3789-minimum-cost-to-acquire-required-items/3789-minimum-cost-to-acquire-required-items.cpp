class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        long long common = std::min(n1, n2);
        long long rem1 = n1 - common;
        long long rem2 = n2 - common;

        long long cost = common * std::min(cb, c1 + c2);
        cost += rem1 * std::min(c1, cb);
        cost += rem2 * std::min(c2, cb);

        return cost;
    }
};