class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        int l = 0,r = 0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(l < n && r < m){
            if(players[l] <= trainers[r]){
                l++;
                r++;
            }
            else r++;
        }
        return l;
    }
};