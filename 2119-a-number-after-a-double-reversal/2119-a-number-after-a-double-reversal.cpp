class Solution {
public:
    int reverse(int n){
        int r=0;
        while(n!=0){
            int l=n%10;
            r=r*10+l;
            n=n/10;
        }
        return r;
        
    }
    bool isSameAfterReversals(int num) {
        bool flag=false;
        cout<<reverse(num);
      if(num==reverse(reverse(num))) flag=true;
      return flag;

        
    }
};