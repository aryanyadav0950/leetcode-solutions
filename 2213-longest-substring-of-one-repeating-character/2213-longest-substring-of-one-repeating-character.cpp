class Solution {
public:
    string s;
    map<int, pair<int,char>> seg; // start -> {end, character}
    multiset<int> sizes;

    // Find the segment containing position p
    map<int, pair<int,char>>::iterator get(int p) {
        auto it = seg.upper_bound(p);
        --it;
        return it;
    }

    void eraseSeg(map<int, pair<int,char>>::iterator it) {
        sizes.erase(sizes.find(it->second.first - it->first + 1));
        seg.erase(it);
    }

    void addSeg(int l, int r, char c) {
        seg[l] = {r, c};
        sizes.insert(r - l + 1);
    }

    vector<int> longestRepeating(string str,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {
        s = str;
        int n = s.size();

        // Build initial runs
        int l = 0;

        for (int i = 1; i <= n; i++) {
            if (i == n || s[i] != s[i - 1]) {
                addSeg(l, i - 1, s[l]);
                l = i;
            }
        }

        vector<int> ans;

        for (int q = 0; q < queryIndices.size(); q++) {
            int p = queryIndices[q];
            char c = queryCharacters[q];

            if (s[p] != c) {
                auto it = get(p);

                int L = it->first;
                int R = it->second.first;
                char old = it->second.second;

                // Remove the old run
                eraseSeg(it);

                // Split the old run around p
                if (L <= p - 1)
                    addSeg(L, p - 1, old);

                if (p + 1 <= R)
                    addSeg(p + 1, R, old);

                s[p] = c;
                addSeg(p, p, c);

                // Merge with left neighbor if same character
                auto cur = get(p);

                if (cur != seg.begin()) {
                    auto left = prev(cur);

                    if (left->second.second == c) {
                        int newL = left->first;
                        int newR = cur->second.first;

                        eraseSeg(left);
                        eraseSeg(cur);

                        addSeg(newL, newR, c);

                        cur = get(p);
                    }
                }

                // Merge with right neighbor if same character
                cur = get(p);
                auto right = next(cur);

                if (right != seg.end() &&
                    right->second.second == c) {

                    int newL = cur->first;
                    int newR = right->second.first;

                    eraseSeg(cur);
                    eraseSeg(right);

                    addSeg(newL, newR, c);
                }
            }

            ans.push_back(*sizes.rbegin());
        }

        return ans;
    }
};