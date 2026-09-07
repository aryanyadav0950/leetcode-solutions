class Solution {
public:
    bool check(int mid,vector<int>& weights,int days){
        int count=0;
        int n=weights.size();
        int mi=mid;
        for(int i=0;i<n;i++){
            int m=weights[i];
            if(m<=mi){
                mi-=m;
            }
            else{
                count++;
                mi=mid;
                mi-=m;
            }    
        }
        if(count<days) return true;
        else return false;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            mx=max(mx,weights[i]);
        }
        int lo=mx;
        int hi=sum;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,weights,days)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;


        
    }
};