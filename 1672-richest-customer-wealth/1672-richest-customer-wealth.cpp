class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m=accounts.size();
        int n=accounts[0].size();
        vector<int> sum;
        for(int i=0;i<m;i++){
            int money=0;
            for(int j=0;j<n;j++){
                money+=accounts[i][j];
            }
            sum.push_back(money);
        }
        sort(sum.begin(),sum.end());
        return sum[m-1];
        
    }
};