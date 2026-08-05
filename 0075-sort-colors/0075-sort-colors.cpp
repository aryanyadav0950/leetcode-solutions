class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int no0=0;
        int no1=0;
        int no2=0;
        for (int i=0;i<n;i++){
            if(nums[i]==0) no0++;
            if(nums[i]==1) no1++;
            if(nums[i]==2) no2++;
        }
        for(int i=0;i<n;i++){
            if(i<no0) nums[i]=0;
            else if(i<no1+no0) nums[i]=1;
            else nums[i]=2;
           
        
        
    }
    }
};