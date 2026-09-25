class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        
        
        sort(nums.begin(), nums.end());
        
       
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        
        vector<int> ans(m);
        
        
        for (int i = 0; i < m; i++) {
            int low = 0, high = n - 1;
            int maxlen = 0;
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] <= queries[i]) {
                    maxlen = mid + 1; 
                    low = mid + 1;   
                } else {
                    high = mid - 1;   
                }
            }
            ans[i] = maxlen;
        }
        
        return ans;
    }
};