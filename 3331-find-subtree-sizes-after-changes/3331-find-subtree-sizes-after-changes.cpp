class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);

        // Step 1: DFS on original tree to determine new parents simultaneously
        auto find_parents = [&](auto& self, int u) -> void {
            int char_idx = s[u] - 'a';
            int prev_ancestor = last_seen[char_idx];
            
            if (prev_ancestor != -1) {
                new_parent[u] = prev_ancestor;
            }
            
            last_seen[char_idx] = u;
            for (int v : adj[u]) {
                self(self, v);
            }
            last_seen[char_idx] = prev_ancestor; // Backtrack
        };

        find_parents(find_parents, 0);

        // Step 2: Build the updated tree
        vector<vector<int>> new_adj(n);
        for (int i = 1; i < n; ++i) {
            new_adj[new_parent[i]].push_back(i);
        }

        // Step 3: DFS on updated tree to calculate subtree sizes
        vector<int> ans(n, 1);
        auto calc_sizes = [&](auto& self, int u) -> int {
            for (int v : new_adj[u]) {
                ans[u] += self(self, v);
            }
            return ans[u];
        };

        calc_sizes(calc_sizes, 0);
        return ans;
    }
};