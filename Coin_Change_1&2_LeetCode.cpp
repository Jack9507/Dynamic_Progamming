// Coin Change 1- 

/*
Time Complexity  : O(A*C)
Space Complexity : O(A)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, 1e5);   // filling the array with some max value because we need to minimize the answer  
        dp[0]=0;        //  coins required to make amount zero.
        
        for(int i=1; i<=amount; i++)
        {
            for(int j=0; j<coins.size(); j++)
            {
                if(coins[j] < i)   // if the coin value is less than the current amt then we can use that coin
                    dp[i] = min(dp[i], 1+ dp[i -coins[j]]);
                else if(i == coins[j])        // if the coin value is equal to amt then we just need 1 coin.
                    dp[i] =1;
                else
                    break; 
            }
        }
        
        return dp[amount] ==1e5 ? -1 : dp[amount] ;
    }
};




// Coin Change 2 -
/* Dynamic Programming Solution
Time Complexity : O(A * C), where 'A' is amount given and 'C' is number fo coins.
Space Complexity : O(A * C), Dp matrix of size A+1, C+1 used to store results.
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int row= coins.size()+1;
        int col= amount + 1;
        vector<vector<int> > dp(row, vector<int> (col,-1));
        
        for(int i=0; i<dp.size(); i++)
            dp[i][0] = 1;   // if amt =0 then there is 1 possible way to do nothing to make change
        for(int  i=1; i<dp[0].size(); i++)
            if(i>0) dp[0][i] = 0;   // if there are no coins available then no ways to make change
        
        for(int i=1; i<dp.size(); i++)
        {
            for(int j=1; j<dp[0].size(); j++)
            {
                if(j-coins[i-1] < 0)  dp[i][j] = dp[i-1][j];     // cannot use just added coin because it exceeds the amt.
                
                if(j-coins[i-1] >=0 )
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];   // sum of not use and use the coin ways.
  
            }
        }
    
        return dp[row-1][col-1];
    }
};
