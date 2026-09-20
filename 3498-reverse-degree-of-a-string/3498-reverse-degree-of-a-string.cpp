class Solution {
public:
    int reverseDegree(string s) {
        int totalSum = 0;
        for (int i = 0; i < s.length(); i++) {
            int reversedAlphabetIndex = 26 - (s[i] - 'a');
            int stringIndex = i + 1;
            totalSum += reversedAlphabetIndex * stringIndex;
        }
        return totalSum;
    }
};