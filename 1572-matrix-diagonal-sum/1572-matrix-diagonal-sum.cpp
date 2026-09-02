class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int psum=0;
        int ssum=0;
        for(int i=0;i<n;i++){
            psum+=mat[i][i];
            ssum+=mat[i][n-1-i];   
        }
        if(n%2==1) psum=psum-mat[n/2][n/2];
    return psum+ssum;    
    }
};