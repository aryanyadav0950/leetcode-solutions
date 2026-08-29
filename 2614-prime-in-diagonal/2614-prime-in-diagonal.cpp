class Solution {
public:
    bool isPrime(int n) {
        if(n<=1) return false;
        if(n==2) return true;
        if(n%2 == 0) return false;
        //int limit = sqrt(n);
        for(int i=2;i<=sqrt(n);i++) {
            if(n%i == 0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int mx=0;
        for(int i=0;i<n;i++) {
            if(isPrime(nums[i][i])) {
                mx = max(mx,nums[i][i]);
            }
            if(isPrime(nums[i][n-i-1])) {
                mx = max(mx,nums[i][n-i-1]);
            }
        }
        return mx;
    }
};