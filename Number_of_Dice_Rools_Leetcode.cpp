class Solution {
public:
    const int mod =1e9+7;
    int helper(int d, int f, int target, vector<vector<int> > &dp)
    {
        if(d==0 && target == 0)
        {
            dp[d][target] =1;
            return 1;
        }
        if(d==0 || target ==0)
        {
            dp[d][target] =0;
            return 0;
        }
        
        if(dp[d][target] != -1)
            return dp[d][target];
        
        int count=0;
         for(int i=1; i<=f; i++)  // iterate over every face in dice
         {
             if(i <= target)       // if current face is less than the target then use it 
             {
                   count += helper(d-1, f, target-i, dp);
                if(count>mod) count %= mod;          // avoids overflow
             }
             else
                 break;     // since faces will come in sorted order so just break out from the loop if face with a value greater                                
                                than target comes because after this face every face will be greater than target.
         }
        count %=mod;
        return dp[d][target]=count;
    }
    int numRollsToTarget(int d, int f, int target) 
    {
        if(target > f*d)
            return 0;
        if(target == f*d)
            return 1;
        int row =d+1;
        int col= target+1;
        vector<vector<int> > dp(row, vector<int> (col,-1));
        
        return helper(d,f,target, dp);
        
    }
};
