class Solution {
public:
    int findClosest(int x, int y, int z) {
        int per1 = abs(z-x);
        int per2= abs(z-y);
        int a=0;
        if(per1>per2) a=2;
        if(per2>per1) a=1;
        
      return a;  
    }
};