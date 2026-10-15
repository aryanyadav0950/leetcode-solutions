class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool> ans(n);
        int mx=0;
        
        for(int x:candies){
            mx=max(x,mx);
        }
        cout<<mx<<endl;
        for(int i=0;i<n;i++){
            if((candies[i]+extraCandies) > mx-1 ) ans[i]="true";
            // else ans[i]="false";
        }
        return ans;
        
    }
};