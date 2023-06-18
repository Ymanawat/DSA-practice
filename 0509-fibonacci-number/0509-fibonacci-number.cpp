class Solution {
private:
    //Recursive way having TC of O(2^n)
    int fibRec(int n){
        //base case
        if (n==0) return 0;
        if (n==1) return 1;
        
        return fibRec(n-1)+fibRec(n-2);
    }
    
    //DP approach having TC of O(n)
    int fibDP(int n){
        //edge case
        if (n==0) return 0;
        vector<int> fibNumbers(n+1,0);
        fibNumbers[0]=0;
        fibNumbers[1]=1;
        
        //storing all numbers in array cancelling the duplicate calculations
        for(int i = 2; i<=n; i++){
            fibNumbers[i]=fibNumbers[i-1]+fibNumbers[i-2];
        }
        return fibNumbers[n];
    }
public:
    int fib(int n) {
        return fibDP(n);
    }
};