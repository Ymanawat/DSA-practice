class Solution {
private:
    
    // TC will be O(n) and Call stack also O(n)
    void reverseRec(vector<char> &s, int l, int r){
        //base case
        if (l>=r){
            return;
        }
        //swap left with right elements
        swap(s[l], s[r]);
        reverseRec(s, l+1, r-1);
    }
public:
    void reverseString(vector<char>& s) {
        reverseRec(s, 0, s.size()-1);
    }
    
};