class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int i = 0;

        while (i < nums.size()) {
            int maxi = INT_MIN;
            int mini = INT_MAX;

            for (int j = 0; j <= i; j++)
                maxi = max(maxi, nums[j]);

            for (int j = i; j < nums.size(); j++)
                mini = min(mini, nums[j]);

            if (maxi - mini <= k)
                return i;

            i++;
        }

        return -1;
    }
};