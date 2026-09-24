class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(i==0){
                res[0]=nums[0];
            }
            
            else res[i]=nums[i]+res[i-1];
        }
        return res;

        
    }
};