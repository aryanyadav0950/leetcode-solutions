class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int x : nums){
            mp[x]++;
        }
        if(k == 1){
            int mx = -1;
            for(int i = 0; i < n; i++){
                if(nums[i] > mx && mp[nums[i]] == 1){
                    mx = nums[i];
                }
            }
            return mx;
        }
        else if(k == n){
            return *max_element(nums.begin(), nums.end());
        }
        else{
            int a = mp[nums[0]];
            int b = mp[nums[n-1]];
            if(a > 1 && b > 1) return -1;
            else if(a == 1 && b == 1) return max(nums[0], nums[n-1]);
            else if(a == 1 && b != 1) return nums[0];
            else return nums[n-1];
        }
        return -1;
    }
};