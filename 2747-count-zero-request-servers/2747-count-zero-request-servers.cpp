class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        vector<pair<int, int>> sortedQueries(m);
        
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        sort(sortedQueries.begin(), sortedQueries.end());
        
        unordered_map<int, int> cnt;
        int left = 0, right = 0;
        int activeServers = 0;
        int logSize = logs.size();
        
        for (int i = 0; i < m; ++i) {
            int qTime = sortedQueries[i].first;
            int qIndex = sortedQueries[i].second;
            int startTime = qTime - x;
            
            while (right < logSize && logs[right][1] <= qTime) {
                int server = logs[right][0];
                if (cnt[server] == 0) {
                    activeServers++;
                }
                cnt[server]++;
                right++;
            }
            
            while (left < logSize && logs[left][1] < startTime) {
                int server = logs[left][0];
                cnt[server]--;
                if (cnt[server] == 0) {
                    activeServers--;
                }
                left++;
            }
            
            ans[qIndex] = n - activeServers;
        }
        
        return ans;
    }
};