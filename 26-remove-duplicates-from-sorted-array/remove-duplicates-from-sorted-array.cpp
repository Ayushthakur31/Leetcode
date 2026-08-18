class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int duplicates = 1;
     for(int i = 0;i < nums.size();i++){
        if(nums[i] != nums[duplicates-1]){
         nums[duplicates] = nums[i];
            duplicates++;
        }
     }
     return duplicates;
}
};