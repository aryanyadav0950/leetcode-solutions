class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums){
            sum+=min(x%3,3-(x%3));

        }
        return sum;
        
    }
};