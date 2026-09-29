class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start, end;

        for(auto x : intervals) {
            start.push_back(x[0]);
            end.push_back(x[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0;
        int j = 0;
        int cnt = 0,maxcnt = 0;
        while(i < n){
          if(start[i] <= end[j]){ 
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxcnt = max(maxcnt,cnt);
        }
        return maxcnt;
    }
};