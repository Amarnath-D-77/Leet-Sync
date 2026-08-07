class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int ans = 10;
        int count = 9;
        int i = 1;

        while (i < n) {
            count *= (10 - i);
            i++;
            ans += count;
        }

        return ans;
    }
};