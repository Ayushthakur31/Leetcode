class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int cnt = 0;
        int l = 0;
        int ans = 0;

        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] % 2 == 1) {
                cnt++;
            }
            while(cnt > k) {
                if(nums[l] % 2 == 1) {
                    cnt--;
                }
                l++;
            }
            ans += r - l + 1;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};