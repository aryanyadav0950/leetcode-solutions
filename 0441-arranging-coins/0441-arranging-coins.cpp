class Solution {
public:
    int arrangeCoins(int n) {
        int x;
        int sum=0;
        int idx ;
        for(int i=1;i<=n/2+1;i++) {
            sum += i;
            x=n-sum;
            idx=i;

            if(x<i+1) break;
        }
        return idx;
    }
};