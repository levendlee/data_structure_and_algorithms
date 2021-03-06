// 169 Majority Element
// https://leetcode.com/problems/majority-element

// version: 1; create time: 2020-02-01 19:16:06;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        const int n = nums.size();
        int major = nums[0];
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (major == nums[i]) {
                ++count;
            } else if (count == 0) {
                major = nums[i];
                count = 1;
            } else {
                --count;
            }
        }
        return major;
    }
};
