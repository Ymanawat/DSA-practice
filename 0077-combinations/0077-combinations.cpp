class Solution {
public:
    
    void solve(int s, int&n, int k, vector<vector<int>> &ans, vector<int> &temp){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        for(int i = s; i <= n; i++){
            temp.push_back(i);
            solve(i+1,n,k-1,ans,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,n,k,ans,temp);
        return ans;    
    }
};