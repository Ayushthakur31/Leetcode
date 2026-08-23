class Solution {
public:
    int f(vector<int>& nums,int divisor){
        int sum = 0;
        for(int x : nums){
            sum += (x + divisor-1)/divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            if(f(nums,mid) <= threshold) high = mid-1;
            else low = mid + 1;
        }
        return low;
    }
};