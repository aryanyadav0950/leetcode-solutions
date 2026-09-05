class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if (s.find(c) != s.end()) {
                ans.push_back(s[c]);
                ans.push_back(i);
            } else
                s[nums[i]] = i;
        }
        return ans;
    }
};