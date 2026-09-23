class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int l = 0;
        int maxi = -1;
        int total = accumulate(nums.begin(),nums.end(),0);
        int target = total - x;
        int sum = 0;
        if(target < 0) return -1;
        for(int r = 0 ;r < n;r++){
            sum += nums[r];
            while(l <= r && sum > target){
                sum -= nums[l];
                l++;
            }
            if(sum == target){
                maxi = max(maxi,r-l+1);
            }
        }
         if(maxi == -1) return -1;
        return n - maxi;
    }
};