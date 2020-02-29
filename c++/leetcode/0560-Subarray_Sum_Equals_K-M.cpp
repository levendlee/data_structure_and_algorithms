// 560 Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k

// version: 1; create time: 2020-01-12 11:49:39;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        sums[0] = 1;
        int acc = 0;
        long total_cnts = 0;
        for (const auto& num : nums) {
            acc += num;
            const auto target = acc - k;
            if (sums.count(target)) {
                total_cnts += sums[target];
            }
            ++sums[acc];
        }
        return total_cnts;
    }
};
