class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int maxi = 0;
        int left = 0;
        for(int i = 0;i < nums.size();i++){
            mpp[nums[i]]++;
        while(mpp[nums[i]] > k){
            mpp[nums[left]]--;
            left++;
        }
        maxi = max(maxi,i-left+1);
        }
        return maxi;
    }
};