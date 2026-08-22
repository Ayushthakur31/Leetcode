class Solution {
public:
bool f(vector<int>& bloomDay,int day,int m,int k){
    int cnt = 0;
    int bucket = 0;
    for(int i = 0;i < bloomDay.size();i++){
        if(bloomDay[i] <= day) cnt++;
        else{
            bucket += cnt/k;
            cnt = 0;
        }
    }
    bucket += cnt/k;
    if(bucket >= m) return true;
    else return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * m * k;
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        if(total > n) return -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(f(bloomDay,mid,m,k)) high = mid-1;
            else low = mid + 1;
        }
        return low;
    }
};