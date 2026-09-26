class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mpp;
        int n = s.size();
        for(auto x : knowledge){
            mpp[x[0]] = x[1];
        }
        string ans = "";
        for(int i = 0;i < n;i++){
            if(s[i] == '('){
                string key = "";
                i++;
                while(s[i] != ')'){
                    key += s[i];
                    i++;
                }
                    if(mpp.find(key) != mpp.end()){
                        ans += mpp[key];
                    }
                    else{
                        ans += "?";
                    }
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};