class Solution {
public:
    int guessNumber(int n) {
        int lo=1;
        int hi=n;
        int ans=0;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int x=guess(mid);

            if(x==1)
                lo=mid+1;
            else if(x==-1)
                hi=mid-1;
            else{
                ans=mid;
                break;
            }
        }

        return ans;
    }
};