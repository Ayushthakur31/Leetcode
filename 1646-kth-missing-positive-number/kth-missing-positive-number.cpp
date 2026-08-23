class Solution {
public:
    int f(vector<int>& arr,int k,int mid){
            int missing = arr[mid] - (mid+1);
        return missing < k;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(f(arr,k,mid)) low = mid + 1;
            else high = mid - 1;
        }
        return low + k;
    }
};