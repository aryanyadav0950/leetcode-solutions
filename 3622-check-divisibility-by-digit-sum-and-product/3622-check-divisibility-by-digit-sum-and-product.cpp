class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            int temp=n%10;
            sum+=temp;
            n=n/10;
        }
        return sum;
    }
    int digitpro(int n){
        int pr=1;
        while(n>0){
            int temp=n%10;
            pr*=temp;
            n=n/10;
        }
        return pr;
    }
    bool checkDivisibility(int n) {
        int summ=digitsum(n)+digitpro(n);
        if(n%summ==0) return true;
        else return false;

        
    }
};