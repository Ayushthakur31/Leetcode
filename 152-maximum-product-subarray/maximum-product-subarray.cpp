class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        for(int i = 0;i < nums.size();i++){
            int product = 1;
            for(int j = i;j < nums.size();j++){
                product *= nums[j];
                maxi = max(maxi,product);
            }
        }
        return maxi;
    }
};