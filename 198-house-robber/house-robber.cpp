class Solution {
public:
//recursion
//     int f(int i,vector<int>& nums){
//         if(i == 0) return nums[0];
//         if(i < 0) return 0;
//         int pick = nums[i] + f(i-2,nums);
//         int notpick = f(i-1,nums);
//         return max(pick,notpick);
//     }
//    int rob(vector<int>& nums) {
//         int  n = nums.size();
//         return f(n-1,nums);
//     }

//Memoisation
//     int f(int i,vector<int>& nums,vector<int>& dp){
//         if(i == 0) return nums[0];
//         if(i < 0) return 0;
//         if(dp[i] != -1) return dp[i];
//         int pick = nums[i] + f(i-2,nums,dp);
//         int notpick = f(i-1,nums,dp);
//         return dp[i] =  max(pick,notpick);
//     }
//    int rob(vector<int>& nums) {
//         int  n = nums.size();
//         vector<int> dp(n+1,-1);
//         return f(n-1,nums,dp);
//     }  

//Tabulation
    // int rob(vector<int>& nums) {
    //      int  n = nums.size();
    //     if(n == 1) return nums[0];
    //     vector<int> dp(n+1,0);
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0],nums[1]);
    //     for(int i = 2;i < n;i++){
    //         int pick = nums[i] + dp[i-2];
    //         int notpick = dp[i-1];
    //          dp[i] =  max(pick,notpick);
    //     }
    //     return dp[n-1];
    // }   

//Space Optimisation    
     int rob(vector<int>& nums) {
         int  n = nums.size();
        if(n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        for(int i = 2;i < n;i++){
            int pick = nums[i] + prev2;
            int notpick = prev1;
             int curr =  max(pick,notpick);
             prev2 = prev1;
             prev1 = curr;
        }
        return prev1;
    }  
};