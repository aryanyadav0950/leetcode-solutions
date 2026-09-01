class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(i!=0){
                left+=nums[i-1];
               
            }
             right=total-left-nums[i];
            if(left==right){
                return i;
               
            }
        }

    return -1;
        
    }
};