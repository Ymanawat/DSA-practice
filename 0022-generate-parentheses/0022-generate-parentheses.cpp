class Solution {
public:
    void solve(int n, int count, vector<string> &ans, string smallans){
    
        if(smallans.length()==n){
          if (count == 0) {
            ans.push_back(smallans);
            return;
          } else {
            return;
          }
        }

        if (count < n / 2) {
          smallans += "(";
          solve(n, count + 1, ans, smallans);
          smallans.pop_back();
        }
        if (count > 0) {
          smallans += ")";
          solve(n, count - 1, ans, smallans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string smallans="(";
        solve(2*n, 1, ans, smallans);
        return ans;    
    }
};