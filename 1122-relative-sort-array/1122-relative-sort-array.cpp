class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            mp[arr1[i]]++;
        }

        for (int i = 0; i < m; i++) {
            while (mp[arr2[i]] > 0) {
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }

        vector<int> rem;

        for (auto x : mp) {
            while (x.second > 0) {
                rem.push_back(x.first);
                x.second--;
            }
        }

        sort(rem.begin(), rem.end());

        for (int i = 0; i < rem.size(); i++) {
            ans.push_back(rem[i]);
        }

        return ans;
    }
};