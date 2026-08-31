class Solution {
public:
    bool isprime(int n) {
        if(n < 2) return false;

        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0)
                return false;
        }

        return true;
    }

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
        while(!isprime(n)) {
            int x = sum(n);

            if(x == n)
                break;

            n = x;
        }

        return n;
    }
};