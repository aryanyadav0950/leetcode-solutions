class Solution {
public:
    bool check(int mid,vector<int>& piles, int h){
        int n=piles.size();
        int count=0;

        for(int i=0;i<n;i++){
            if(count>h) return false;
            if(mid>=piles[i]) count++;
            else if(piles[i]%mid==0)
                count+=piles[i]/mid;
            else
                count+=(piles[i]/mid)+1;
        }

        if(count>h) return false;
        else return true;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int sum=0;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,piles[i]);
        }
        int lo=1;
        int hi=mx;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,piles,h)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;

        
    }
};