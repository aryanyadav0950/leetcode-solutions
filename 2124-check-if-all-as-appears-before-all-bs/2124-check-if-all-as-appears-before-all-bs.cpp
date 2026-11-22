class Solution {
public:
    bool checkString(string s) {
        bool seenB = false;
        
        for (char c : s) {
            if (c == 'b') {
                seenB = true;
            } else if (seenB) {
                // Found an 'a' after a 'b' has already appeared
                return false;
            }
        }
        
        return true;
    }
};