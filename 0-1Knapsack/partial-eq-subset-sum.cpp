class Solution {
public:
    int dp[200][200*100];
    
    bool subsetSum(vector<int> &nums, int i, int currSum, int targetSum) {
        //base condition
        if(currSum == targetSum) { return true; }
        if(i >= nums.size() and currSum != targetSum) { return false; }
        
        //if it was already computed and stored in dp array then we don't need to go for recursion. simply return the value 
        if(dp[i][currSum] != -1) { return dp[i][currSum]; }
        
        //recursion

        if(nums[i] > targetSum) { 
            return false; 
        }
        
        // if(nums[i] <= sum) first store it in dp array then return value from function call 
        dp[i][currSum] = (subsetSum(nums, i+1, currSum+nums[i], targetSum)) || subsetSum(nums, i+1, currSum, targetSum);
        
        return dp[i][currSum];
    }
    
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        
        int sum = 0;
        for(auto x:nums) { sum += x; }
        
        if(sum%2 != 0) { return false; }
        
        //if sum is even (sum%2 == 0)
        else {
            int n = nums.size();
            return subsetSum(nums, 0, 0, sum/2);
        }
    }
};
                            
