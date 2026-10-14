class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0;
        int a=n;
        while(n>0){
            int temp=n%10;
            rev=(rev*10)+temp;
            n=n/10;
        }
        return abs(a-rev);
        
    }
};