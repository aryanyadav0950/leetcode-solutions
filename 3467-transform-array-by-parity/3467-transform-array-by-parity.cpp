class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int ceven=0;
        int codd=0;
        for(auto x:nums){
            if(x%2==0) ceven++;
            else codd++;
        }
        for(int i=0;i<ceven;i++){
            nums[i]=0;
        }
        for(int i=ceven;i<nums.size();i++){
            nums[i]=1;
        }

        return nums;
        
    }
};