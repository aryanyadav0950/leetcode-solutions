class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int squaresum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }
    bool checkGoodInteger(int n){
        if (squaresum(n)-digitsum(n) >=50) return true;
        else return false;
        
    }
};