// 29 Divide Two Integers
// https://leetcode.com/problems/divide-two-integers

// version: 1; create time: 2020-02-06 00:19:59;
class Solution {
public:
    int divide(long dividend, long divisor) {
        int sign = dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0 ? 1 : -1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        long lo = 0, hi = dividend;
        while (lo < hi) {
            long mid = lo + (hi - lo + 1) / 2;
            if (divisor * mid > dividend) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        auto res = lo * sign;
        return res > INT_MAX ? INT_MAX : res;
    }
};
