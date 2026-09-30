class Solution {
public:
    int gd(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return n/i;
    }
        return 1;
    }
    int minSteps(int n) {
       int count=0;
        while(n>1){
             int hf=gd(n);
        count+=n/hf;
        n=hf;
        }
    return count;   
    } 
};