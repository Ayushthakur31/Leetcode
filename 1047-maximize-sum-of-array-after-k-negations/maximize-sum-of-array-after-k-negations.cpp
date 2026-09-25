class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        while(i < n && k > 0){
                if(nums[i] < 0){
                    nums[i] = -nums[i];
                   k--;
                   i++;
                }
                else break;
        }
        if(k % 2 == 1){
            sort(nums.begin(),nums.end());
            nums[0] = -nums[0];
        }
        int sum = 0;
        for(int x : nums){
            sum += x;
        }
        return sum;
    }
};