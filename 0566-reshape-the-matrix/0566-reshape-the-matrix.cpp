class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) return mat;
        vector<int> arr;
        vector<vector< int >> ans(r,vector<int>(c));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                arr.push_back(mat[i][j]);
            }
        }
        int idx = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = arr[idx++];
            }
        }
        return ans;
    }
};