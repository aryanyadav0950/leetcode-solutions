class Solution {
public:
    bool check(int n){
        if(n%3==0||n%5==0||n%7==0) return true;
        else return false;
    }
    int sumOfMultiples(int n) {
        int sum=0;
        for(int i=1;i<n+1;i++){
            if(check(i)){
                sum+=i;
            }
        }
        return sum;

        
    }
};