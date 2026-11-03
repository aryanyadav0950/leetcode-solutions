class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = nums[0];
        for (int num : nums) {
            if (num > max_val) {
                max_val = num;
            }
        }
        
        int moves = 0;
        for (int num : nums) {
            moves += (max_val - num);
        }
        
        return moves;
    }
};