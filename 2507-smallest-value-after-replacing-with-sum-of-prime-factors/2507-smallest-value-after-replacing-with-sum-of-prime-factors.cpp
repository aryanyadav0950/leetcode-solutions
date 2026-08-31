class Solution {
public:
    int sum(int n) {
        int s = 0;

        for(int i = 2; i <= n; i++) {
            while(n % i == 0) {
                s += i;
                n /= i;
            }
        }

        return s;
    }

    int smallestValue(int n) {
        while(true) {
            int x = sum(n);

            if(x == n)
                return n;

            n = x;
        }
    }
};