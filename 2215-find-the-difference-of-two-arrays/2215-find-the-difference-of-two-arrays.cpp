class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1;
        vector<int> ans2;

        for (int i = 0; i < nums1.size(); i++) {
            bool flag = false;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                // Check for duplicate in ans1 before pushing
                bool exists = false;
                for (int k = 0; k < ans1.size(); k++) {
                    if (ans1[k] == nums1[i]) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    ans1.push_back(nums1[i]);
                }
            }
        }

        // Find elements in nums2 that are not in nums1
        for (int i = 0; i < nums2.size(); i++) {
            bool flag = false;
            for (int j = 0; j < nums1.size(); j++) {
                if (nums2[i] == nums1[j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                // Check for duplicate in ans2 before pushing
                bool exists = false;
                for (int k = 0; k < ans2.size(); k++) {
                    if (ans2[k] == nums2[i]) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    ans2.push_back(nums2[i]);
                }
            }
        }

        return {ans1, ans2};
    }
};