class Solution {
public:
    bool isPalindrome(string s) {
        int n =s.size();
        string ans;
        string rans;
        for(int i=0;i<n;i++){
            if(isalpha(s[i])) ans+= tolower(s[i]);
            if(isdigit(s[i])) ans+=s[i];
        }
        rans=ans;
        reverse(ans.begin(),ans.end());
        if(ans==rans) return true;
        else return false;
    }

};