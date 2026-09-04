class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = -1e9;
        int mini = 1e9;

       for(int i = 0;i < n;i++){
        maxi = max(maxi,nums[i]);
        mini = *min_element(nums.begin()+i,nums.end());
        if(maxi - mini <= k) return i;
       }
        return -1;
    }
};