class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool aliceTurn = true;
        
        while (n >= stones && stones > 0) {
            n -= stones;
            stones--;
            aliceTurn = !aliceTurn;
        }
        
        return !aliceTurn;
    }
};