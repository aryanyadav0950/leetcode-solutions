class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int c0 = 0, c1 = 0, c2 = 0;
        
        // Count frequencies of remainders modulo 3
        for (int stone : stones) {
            int rem = stone % 3;
            if (rem == 0) c0++;
            else if (rem == 1) c1++;
            else c2++;
        }
        
        // Case 1: Even number of 0-remainder stones
        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        }
        
        // Case 2: Odd number of 0-remainder stones
        return std::abs(c1 - c2) > 2;
    }
};