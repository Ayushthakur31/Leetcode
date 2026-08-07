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
    int f(int i,vector<int>& nums,vector<int>& dp){
        if(i == 0) return nums[0];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + f(i-2,nums,dp);
        int notpick = f(i-1,nums,dp);
        return dp[i] =  max(pick,notpick);
    }
   int rob(vector<int>& nums) {
        int  n = nums.size();
        vector<int> dp(n+1,-1);
        return f(n-1,nums,dp);
    }    
};