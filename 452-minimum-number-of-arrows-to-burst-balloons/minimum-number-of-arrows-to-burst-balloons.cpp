class Solution {
public:
    static bool comp(vector<int> v1,vector<int> v2){
        return v1[1] < v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),comp);
        int cnt = 1;
        int lastendtime = points[0][1];
        for(int i = 1;i < n;i++){
            if(points[i][0] > lastendtime){
                cnt++;
                lastendtime = points[i][1];
            }
        }
        return cnt;
    }
};