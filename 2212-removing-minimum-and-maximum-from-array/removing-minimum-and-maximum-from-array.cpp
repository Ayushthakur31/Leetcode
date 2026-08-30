class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = 1e9;
        int maxi = -1e9;
        int n = nums.size();
        int minind = -1;
        int maxind = -1;
        for(int i = 0;i < n;i++){
           if(nums[i] < mini){
            mini = nums[i];
            minind = i;
           }
           if(nums[i] > maxi){
            maxi = nums[i];
            maxind = i;
           }
        }
        int left = max(minind,maxind) + 1;
        int right = n - min(minind,maxind);
        int cross = min(minind,maxind) + 1 + n - max(minind,maxind);
        return min({left,right,cross});
    }
};