class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < cols; j++) {
                    if(grid[i][j] == 0)
                        grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
            }
        }

        for(int j = 0; j < cols; j++) {
            int noz = 0;
            int noo = 0;

            for(int i = 0; i < rows; i++) {
                if(grid[i][j] == 0)
                    noz++;
                else
                    noo++;
            }

            if(noz > noo) {
                for(int i = 0; i < rows; i++) {
                    if(grid[i][j] == 0)
                        grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < rows; i++) {
            int num = 0;

            for(int j = 0; j < cols; j++) {
                num = num * 2 + grid[i][j];
            }

            ans += num;
        }

        return ans;
    }
};