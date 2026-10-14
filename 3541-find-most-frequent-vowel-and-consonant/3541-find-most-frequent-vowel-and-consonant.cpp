class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        string v = "aeiou";
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        
        int vmax = 0;
        int cmax = 0;

        for (auto x : mp) {
            char ch = x.first;
            int freq = x.second;

            bool isVowel = false;
            for (int i = 0; i < 5; i++) {
                if (ch == v[i]) {
                    isVowel = true;
                    break;
                }
            }
            
            if (isVowel) {
                vmax = max(vmax, freq);
            } else {
                cmax = max(cmax, freq);
            }
        }
        
        return cmax + vmax;
    }
};