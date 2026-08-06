class Solution {
public:

    int product(int n) {
        int temp = n;
        int pr = 1;

        while (temp > 0) {
            int ntemp = temp % 10;
            pr = pr * ntemp;
            temp = temp / 10;
        }

        return pr;
    }

    int smallestNumber(int n, int t) {

        for (int i = n; i <= n + 10; i++) {

            if (product(i) % t == 0) {
                return i;
            }

        }

        return -1;
    }
};