// 31 Next Permutation
// https://leetcode.com/problems/next-permutation

// version: 1; create time: 2020-01-18 18:37:21;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return;

        for (int i = n - 1; i > 0; --i) {
            if (nums[i-1] < nums[i]) {
                int j = n - 1;
                while (j >= i) {
                    if (nums[j] > nums[i-1]) break;
                    --j;
                }
                std::swap(nums[i-1], nums[j]);
                std::reverse(nums.begin() + i, nums.end());
                return;
            }
        }

        std::reverse(nums.begin(), nums.end());
        return;
    }
};
