class Solution {
public:
    int gcd(int a,int b){
        if(a==0) return b;
        else return gcd(b%a,a);
    }
    int findGCD(vector<int>& nums) {
        int a=INT_MAX;
        int b=INT_MIN;
        for(int x:nums){
            a=min(a,x);
            b=max(b,x);
        }
        return gcd(a,b);

        
    }
};