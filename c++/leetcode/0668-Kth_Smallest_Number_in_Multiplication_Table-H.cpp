// 668 Kth Smallest Number in Multiplication Table
// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table

// version: 1; create time: 2019-12-26 15:44:01;
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if (m > n) {
            std::swap(m, n);
        }
        int lo = 1, hi = k, mid, cnt, idx;
        int candidate;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            cnt = 0;
            candidate = INT_MIN;
            for (int i = 1; i <= m; ++i) {
                idx = std::min(mid / i, n);
                cnt += idx;
                candidate = std::max(idx * i, candidate);
            }
            if (cnt < k) {
                lo = mid + 1;
            } else if (cnt > k) {
                hi = mid;
            } else {
                return candidate;
            }
        }
        return lo;
    }
};
