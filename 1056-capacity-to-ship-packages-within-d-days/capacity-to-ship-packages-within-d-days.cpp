class Solution {
public:
    int f(vector<int>& weights,int days,int cap){
        int cnt = 1;
        int load = 0;
        for(int x : weights){
            if(load + x <= cap)
             load += x; 
              else{
            cnt++;
            load = x;
        }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low  = *max_element(weights.begin(),weights.end());
        int high = 0;
        for(int x : weights){
            high += x;
        }
        while(low <= high){
            int mid = low + (high-low)/2;
            if(f(weights,days,mid))
                high = mid-1;
            else low = mid + 1;    
        }
        return low;
    }
};