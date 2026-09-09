class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        unordered_map<int, int> mp;
        for (auto x : nums) {
            mp[x]++;
        }
        for (auto x : mp) {
            if (x.second == 1) ans=x.first;
        }
    return ans;

    }
};