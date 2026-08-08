class Solution {
public:
//Recursion
//     int f(int i,int n,vector<int>& nums){
//         if(i >= n) return 0;
//         int pick = nums[i] + f(i+2,n,nums);
//         int notpick = f(i+1,n,nums);
//         return max(pick,notpick);
//     }
//    int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return nums[0];

//         int case1 = f(0,n-1,nums);
//         int case2 = f(1,n,nums);
//         return max(case1,case2);
//     }

//Memoization
//     	  int f(int i,int n,vector<int>& nums,vector<int>& dp){
//         if(i >= n) return 0;
//         if(dp[i] != -1) return dp[i];
//         int pick = nums[i] + f(i+2,n,nums,dp);
//         int notpick = f(i+1,n,nums,dp);
//         return dp[i] = max(pick,notpick);
//     }
//    int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return nums[0];
//         vector<int> dp1(n+1,-1);
//         int case1 = f(0,n-1,nums,dp1);
//         vector<int> dp2(n+1,-1);
//         int case2 = f(1,n,nums,dp2);
//         return max(case1,case2);
//     }

//Tabulation
   int f(int i,int n,vector<int>& nums){
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = nums[i];
        for(int x = 2;x <= n-i;x++){
        int pick = nums[i+ x-1] + dp[x-2];
        int notpick = dp[x-1];
         dp[x] = max(pick,notpick);
        }
        return dp[n-i];
    }
   int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int case1 = f(0,n-1,nums);
        int case2 = f(1,n,nums);
        return max(case1,case2);
    }
};