    class Solution {
    public:
    //Recursion
        // int f(vector<int>& nums,int target){
        //     if(target == 0) return 1;
        //     if(target < 0) return 0;
        //     int ans = 0;
        //     for(int i = 0;i < nums.size();i++){
        //         ans += f(nums,target-nums[i]);
        //     }
        //     return ans;
        // }
        // int combinationSum4(vector<int>& nums, int target) {
        //     return f(nums,target);
        // }

    //Memoisation
        // int f(vector<int>& nums,int target,vector<int>& dp){
        //     if(target == 0) return 1;
        //     if(target < 0) return 0;
        //     if(dp[target] != -1) return dp[target];
        //     int ans = 0;
        //     for(int i = 0;i < nums.size();i++){
        //         ans += f(nums,target-nums[i],dp);
        //     }
        //     return dp[target] = ans;
        // }
        // int combinationSum4(vector<int>& nums, int target) {
        //     vector<int> dp(target+1,-1);
        //     return f(nums,target,dp);
        // }   

    //Tabulation
        // int combinationSum4(vector<int>& nums, int target) {
        //     vector<int> dp(target+1,0);
        //     dp[0] = 1;
        //     for(int j = 1;j <= target;j++){
        //     int ans = 0;
        //     for(int i = 0;i < nums.size();i++){
        //         if(nums[i] <= j)
        //         ans += dp[j - nums[i]];
        //     }
        //     dp[j] = ans;
        //     }
        //     return dp[target];
        // }     

    //space optimisation
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target + 1, 0);

        dp[0] = 1;

        for(int j = 1; j <= target; j++) {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] <= j) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }

        return (int)dp[target];
    }
    };