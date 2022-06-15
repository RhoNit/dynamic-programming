class Solution{   
public:
    int dp[100][100*100];
    int helper(vector<int> &arr, int i, int currSum, int targetSum) {
        //base case
        if(currSum == targetSum) { return 1; }
        if(i == arr.size() and currSum != targetSum) { return 0; }
        
        //checking if it is already present there in dp array
        if(dp[i][currSum] != -1) { return dp[i][currSum]; }
        
        //recursive call
        if(arr[i] > targetSum) {
            return dp[i][currSum] = helper(arr, i+1, currSum, targetSum);
        }
        //storing in dp array + recursive call
        else { 
            dp[i][currSum] = (helper(arr, i+1, currSum+arr[i], targetSum) || helper(arr, i+1, currSum, targetSum));
            return dp[i][currSum];
        }
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        memset(dp, -1, sizeof(dp));
        return helper(arr, 0, 0, sum);
    }
};