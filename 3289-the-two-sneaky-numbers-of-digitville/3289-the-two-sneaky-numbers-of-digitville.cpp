class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> arr(2);
        int u=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            if(x.second==2) arr[u++]=x.first;
        }
        return arr;
        
    }
};