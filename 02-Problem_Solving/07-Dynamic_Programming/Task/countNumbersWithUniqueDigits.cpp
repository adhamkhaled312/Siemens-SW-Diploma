//https://leetcode.com/problems/count-numbers-with-unique-digits/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int total = 10;
        int prod = 9;
        for (int i = 2; i < n + 1; i++) {
            total += prod * (11 - i);
            prod *= 11 - i;
        }
        return total;
    }
};
