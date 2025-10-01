class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int fullBottle = 0;
        int num = 0;

        while (numBottles > 0) {
            num += numBottles;
            emptyBottles += numBottles;

            
            fullBottle = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange;

            numBottles = fullBottle;
        }

        return num;
    }
};
