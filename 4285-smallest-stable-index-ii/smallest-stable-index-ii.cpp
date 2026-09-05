class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // int n = nums.size();
        // int maxi = -1e9;
        // int mini = 1e9;
        // for(int i = 0;i < n;i++){
        //     maxi = *max_element(nums.begin(),nums.begin()+i+1);
        //     mini = *min_element(nums.begin()+i,nums.end());
        //     if(maxi - mini <= k) return i;
        // }
        // return -1;

        int n = nums.size();
        vector<int> prefixmax(n);
        vector<int> suffixmin(n);

        prefixmax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixmax[i] = max(prefixmax[i - 1], nums[i]);
        }

        suffixmin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixmin[i] = min(suffixmin[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (prefixmax[i] - suffixmin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};