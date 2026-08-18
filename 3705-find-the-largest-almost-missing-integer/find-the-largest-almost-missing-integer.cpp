class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;

        int ans = -1;

        // k == n: only one subarray
        if (k == n) {
            for (auto it : freq) {
                ans = max(ans, it.first);
            }
            return ans;
        }

        // k == 1: each element is its own subarray
        if (k == 1) {
            for (int x : nums) {
                if (freq[x] == 1)
                    ans = max(ans, x);
            }
            return ans;
        }

        // 1 < k < n
        // Only first and last positions occur in exactly one window
        if (freq[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if (freq[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};