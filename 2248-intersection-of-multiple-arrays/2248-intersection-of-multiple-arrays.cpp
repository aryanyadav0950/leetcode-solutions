class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_map<long long,long long> mp;
        int n=nums.size();
        // int m= nums[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                mp[nums[i][j]]++;
            }
        }
        for(auto x:mp){
            if(x.second ==n){
                ans.push_back(x.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};