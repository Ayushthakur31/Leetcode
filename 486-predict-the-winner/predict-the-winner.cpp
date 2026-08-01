class Solution {
public:
// int f(int i,int j,vector<int> &nums){
//     if(i == j) return nums[i];
//     int left = nums[i] - f(i+1,j,nums);
//     int right = nums[j] - f(i,j-1,nums);
//     return max(left,right);

// }
//     bool predictTheWinner(vector<int>& nums) {
//         return f(0,nums.size()-1,nums) >= 0;
//     }

//memoization
// int f(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
//     if(i == j) return nums[i];
//     if(dp[i][j] != -1) return dp[i][j];
//     int left = nums[i] - f(i+1,j,nums,dp);
//     int right = nums[j] - f(i,j-1,nums,dp);
//     return dp[i][j] = max(left,right);

// }
    // bool predictTheWinner(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>>dp(n,vector<int> (n,-1));
    //     return f(0,nums.size()-1,nums,dp) >= 0;
    // }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int> (n,-1));
        for(int i = 0;i < n;i++){
            dp[i][i] = nums[i];
        }
        for(int i = n-2;i >= 0;i--){
            for(int j = i+1;j < n;j++){
                int left = nums[i] - dp[i+1][j];
                int right = nums[j] - dp[i][j-1];
                dp[i][j] = max(left,right);
            }
        }
        return dp[0][n-1] >= 0;
    }
};