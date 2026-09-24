class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start=0;
        int ans=0;
        int count=0;
        for(int end=0;end<nums.size();end++){
            if(nums[end]==0) count++;
            while(count>1){
                if(nums[start]==0) count--;
                start++;
            }
            ans=max(ans,end-start+1);
        }
        return ans-1;
    }
};