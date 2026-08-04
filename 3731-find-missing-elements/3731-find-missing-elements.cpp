class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[0];
        for (int i=0;i<nums.size();i++){
            if(mini>nums[i])
                mini=nums[i];
            if(maxi<nums[i]) 
                maxi=nums[i];
        }    
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(find(nums.begin(),nums.end(),i) == nums.end()){
                ans.push_back(i);

            }
        }
        return ans;
        
        
    }
};