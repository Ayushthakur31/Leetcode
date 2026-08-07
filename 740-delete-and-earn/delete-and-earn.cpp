class Solution {
public:
//recursion
    // int f(int i,vector<int>& earn){
    //          if(i == 0) return earn[0];
    //          if(i <= 0) return 0;
    //         int pick = earn[i] + f(i-2,earn);
    //         int notpick = f(i-1,earn);
    //         return max(pick,notpick);
    // }
    // int deleteAndEarn(vector<int>& nums) {
    //     int n = nums.size();
    //     int mx = *max_element(nums.begin(),nums.end());
    //     vector<int> earn(mx+1,0);
    //         for(int x : nums){
    //             earn[x] += x;
    //         }
    //     return f(mx,earn);
    // }

//Memoisation
    // int f(int i,vector<int>& earn,vector<int> &dp){
    //          if(i == 0) return earn[0];
    //          if(i < 0) return 0;
    //          if(dp[i] != -1) return dp[i];
    //         int pick = earn[i] + f(i-2,earn,dp);
    //         int notpick = f(i-1,earn,dp);
    //         return max(pick,notpick);
    // }
    // int deleteAndEarn(vector<int>& nums) {
    //     int n = nums.size();
    //     int mx = *max_element(nums.begin(),nums.end());
    //     vector<int> earn(mx+1,0);
    //     vector<int> dp(mx+1,-1);
    //         for(int x : nums){
    //             earn[x] += x;
    //         }
    //     return f(mx,earn,dp);
    // }

//Tabulation
    // int deleteAndEarn(vector<int>& nums) {
    //     int n = nums.size();
    //     int mx = *max_element(nums.begin(),nums.end());
    //     vector<int> earn(mx+1,0);
    //     vector<int> dp(mx+1,0);
    //         for(int x : nums){
    //             earn[x] += x;
    //         }
    //         dp[0] = earn[0];
    //         dp[1] = max(earn[0],earn[1]);
    //         for(int i = 2;i <= mx;i++){
    //            int pick = earn[i] + dp[i-2];
    //            int notpick = dp[i-1];
    //            dp[i] =  max(pick,notpick);
    //            }
    //     return dp[mx];
    // }   

//Space Optimisation
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> earn(mx+1,0);
            for(int x : nums){
                earn[x] += x;
            }
            if(mx == 0) return earn[0];
            int prev2 = earn[0];
            int prev1 = max(earn[0],earn[1]);
            for(int i = 2;i <= mx;i++){
               int pick = earn[i] + prev2;
               int notpick = prev1;
               int curr =  max(pick,notpick);

              prev2 = prev1;
              prev1 = curr;             
         }
        return prev1;
    }      
};