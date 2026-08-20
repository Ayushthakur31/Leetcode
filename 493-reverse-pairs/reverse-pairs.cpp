class Solution {
public:
//BruteForce    
        // int cnt = 0;
        // for(int i = 0;i < nums.size();i++){
        //     for(int j = i+1;j < nums.size();j++){
        //         if(i < j && nums[i] > 2LL * nums[j]) cnt++;
        //     }
        // }
        // return cnt;

    int mergesort(vector<int>& nums,int low,int high){
        if(low >= high) return 0;
        int mid = low + (high-low)/2;
        int cnt = 0;
        cnt += mergesort(nums,low,mid);
        cnt += mergesort(nums,mid+1,high);
        int j = mid + 1;
        for(int i = low;i <= mid;i++){
            while(j <= high && nums[i] > 2LL*nums[j]){
                j++;
            }
            cnt += j - (mid + 1);
        }
        vector<int> temp;
        int i = low;
         j = mid + 1;
        while(i <= mid && j <= high){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            } 
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k = low;k <= high;k++){
            nums[k] = temp[k-low];
        }
        return cnt;
    }    
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};