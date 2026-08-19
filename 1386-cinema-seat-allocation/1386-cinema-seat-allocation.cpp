class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> rows;

        // Store reserved seats only for affected rows
        for (auto &seat : reservedSeats) {
            rows[seat[0]].insert(seat[1]);
        }

        // Every completely empty row can fit 2 groups
        int ans = (n - rows.size()) * 2;

        for (auto &[row, seats] : rows) {

            bool left = true;    // 2,3,4,5
            bool middle = true;  // 4,5,6,7
            bool right = true;   // 6,7,8,9

            for (int s = 2; s <= 5; s++)
                if (seats.count(s))
                    left = false;

            for (int s = 4; s <= 7; s++)
                if (seats.count(s))
                    middle = false;

            for (int s = 6; s <= 9; s++)
                if (seats.count(s))
                    right = false;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};