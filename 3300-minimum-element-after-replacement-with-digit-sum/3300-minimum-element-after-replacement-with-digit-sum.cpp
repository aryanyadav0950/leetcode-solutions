class Solution {
public:
    int sum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mi=INT_MAX;
        for(auto x:nums){
            mi=min(sum(x),mi);
        }
        return mi;
    }
};