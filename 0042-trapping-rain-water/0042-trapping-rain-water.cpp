class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        if (n == 0) return 0;

        vector<int> prev(n);

        // Left greatest array
        int maxi = height[0];
        prev[0] = -1;

        for (int i = 1; i < n; i++) {
            prev[i] = maxi;
            if (height[i] > maxi)
                maxi = height[i];
        }

        // Right greatest array (reuse prev array)
        prev[n - 1] = -1;
        maxi = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (maxi < prev[i])
                prev[i] = maxi;

            if (height[i] > maxi)
                maxi = height[i];
        }

        // Calculate trapped water
        int water = 0;

        for (int i = 1; i < n - 1; i++) {
            if (height[i] < prev[i]) {
                water += (prev[i] - height[i]);
            }
        }

        return water;
    }
};