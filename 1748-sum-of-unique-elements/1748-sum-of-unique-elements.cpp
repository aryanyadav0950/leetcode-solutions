class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum=0;
        for(auto x:nums){
            mp[x]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]<2) sum+=nums[i];
        }
        return sum;

        
    }
};