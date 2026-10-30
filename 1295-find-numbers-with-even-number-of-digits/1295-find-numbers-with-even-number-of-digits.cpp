class Solution {
public:
    bool digit(int n){
        int no=0;
        while(n!=0){
            no++;
            n=n/10;
        }
        if(no%2==0) return true;
        else return false;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto x:nums){
            if(digit(x)) count++;
        }
        return count;
        
    }
};