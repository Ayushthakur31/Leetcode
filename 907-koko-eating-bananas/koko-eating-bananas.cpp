class Solution {
public:
    int findmax(vector<int>& piles){
        int maxi = -1e9;
        for(int x : piles){
            maxi = max(maxi,x);
        }
        return maxi;
    }
    long long func(vector<int>& piles,int hourly){
        long long totalHr = 0;
        for(int x : piles){
            totalHr += (x + 1LL * hourly-1)/hourly;
        }
        return totalHr; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);
        while(low <= high){
            int mid = low + (high-low)/2;
    	    long long totalHr = func(piles,mid);
             if(totalHr <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};