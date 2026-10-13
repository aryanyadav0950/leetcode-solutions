class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n=order.size();
        int f=friends.size();
        vector<int> ans(f);
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<f;j++){
                if(order[i]==friends[j]) ans[k++]=order[i];
            }
        }
        return ans;
    }
};