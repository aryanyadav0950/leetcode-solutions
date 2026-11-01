class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = nums[0];
        long long sum = 0;
        
        for (int num : nums) {
            minVal = min(minVal, num);
            sum += num;
        }
        
        return sum - (long long)minVal * nums.size();
    }
};