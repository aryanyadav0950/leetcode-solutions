class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> arr(150,1000);
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            int idx=(int)s[i];
            if(arr[idx]==1000) arr[idx]=s[i]-t[i];
            else if(arr[idx]!=s[i]-t[i]) return false;

        }
        for(int i=0;i<150;i++){
            arr[i]=1000;
        }
        for(int i=0;i<t.size();i++){
            int idx=(int)t[i];
            if(arr[idx]==1000) arr[idx]=t[i]-s[i];
            else if(arr[idx]!=t[i]-s[i]) return false;
        }
    return true;    
    }
};