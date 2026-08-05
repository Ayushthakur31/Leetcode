class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int freq = 0;
        int ans = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == nums[i-1]){
                freq++;
            }
            else{
                freq = 1;
            }
            ans = nums[i];
            if(freq > n/2) return ans;
        }
        return nums[0];
    }
};