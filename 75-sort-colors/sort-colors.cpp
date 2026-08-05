class Solution {
public:
    void sortColors(vector<int>& nums) {
       int left = 0;
       int right = nums.size() - 1;
       int n = nums.size();
       for(int i = 0;i < n;i++){
        if(nums[i] == 0){
            swap(nums[i],nums[left]);
            left++;
        }
       }
       for(int i = n-1;i >= 0;i--){
        if(nums[i] == 2){
            swap(nums[i],nums[right]);
            right--;
        }
       }
    }
};