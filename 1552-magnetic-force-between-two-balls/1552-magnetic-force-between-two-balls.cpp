class Solution {
public:
    bool isPossible(vector<int> & arr, int m, int mid){
        int last = arr[0];
        int balls = 1;
        for(int x : arr){
            if(x - last >= mid){
                balls++;
                last = x;
            }
            if(balls >= m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1;
        int high = position[n - 1] - position[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(position, m, mid)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};