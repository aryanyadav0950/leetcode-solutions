class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        // dp[i] = true if the player whose turn it is
        // can force a win with i stones.

        for (int i = 1; i <= n; i++) {

            // Try removing every possible square number
            for (int j = 1; j * j <= i; j++) {

                // If after our move the opponent is in
                // a losing position, we can win.
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};