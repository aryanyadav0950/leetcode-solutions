class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busy_servers;

        vector<int> ans(m);
        long long current_time = 0;

        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);

            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= current_time) {
                auto [free_time, weight, idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({weight, idx});
            }

            if (free_servers.empty()) {
                current_time = get<0>(busy_servers.top());
                while (!busy_servers.empty() && get<0>(busy_servers.top()) <= current_time) {
                    auto [free_time, weight, idx] = busy_servers.top();
                    busy_servers.pop();
                    free_servers.push({weight, idx});
                }
            }

            auto [weight, idx] = free_servers.top();
            free_servers.pop();

            ans[j] = idx;
            busy_servers.push({current_time + tasks[j], weight, idx});
        }

        return ans;
    }
};