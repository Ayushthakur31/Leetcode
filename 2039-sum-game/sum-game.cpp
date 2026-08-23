class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftsum = 0;
        int rightsum = 0;
        int leftq = 0;
        int rightq = 0;
        for(int i = 0;i < n;i++){
            if(i < n/2){
                if(num[i] == '?') leftq++;
                else leftsum += num[i] - '0';
            }
            else{
                if(num[i] == '?') rightq++;
                else rightsum += num[i] - '0';
            }
        }
        if((leftq + rightq) % 2 == 1) return true;
           return leftsum - rightsum !=
               9 * (rightq - leftq) / 2;
    }
};