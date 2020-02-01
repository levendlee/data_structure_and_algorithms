class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n < 2) return false;
        if (k == 0) {
            int cnt0 = 0;
            for (const auto& num : nums) {
                cnt0 = num == 0 ? cnt0 + 1 : 0;
                if (cnt0 >= 2) return true;
            }
            return false;
        }
        if (abs(k) == 1) return nums.size() >= 2;

        int pre_sum = 0, cur_sum = 0, nex_sum = 0;
        unordered_set<int> rems;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                rems.insert(pre_sum % k);
            }
            nex_sum = cur_sum + nums[i];
            const auto r = nex_sum % k;
            if (rems.count(r)) return true;
            pre_sum = cur_sum;
            cur_sum = nex_sum;
        }
        return false;
    }
};