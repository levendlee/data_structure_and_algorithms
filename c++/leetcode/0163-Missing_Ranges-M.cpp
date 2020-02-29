// 163 Missing Ranges
// https://leetcode.com/problems/missing-ranges

// version: 1; create time: 2019-11-07 22:08:29;
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        const size_t n = nums.size();

        vector<string> res;
        long long prev = lower - 1LL;
        for (size_t i = 0; i <= n; ++i) {
            long long num = i == n ? upper + 1LL : nums[i];
            if (num > prev + 1) {
                if (num == prev + 2) {
                    res.push_back( std::to_string(prev + 1) );
                } else {
                    res.push_back( std::to_string(prev + 1) + "->" + std::to_string(num - 1) );
                }
            }
            prev = num;
        }
        return res;
    }
};
