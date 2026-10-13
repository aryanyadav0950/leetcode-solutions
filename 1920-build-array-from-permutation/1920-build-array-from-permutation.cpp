class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            int a=nums[i];
            ans[i]=nums[a];
        }
        return ans;    
    }
};