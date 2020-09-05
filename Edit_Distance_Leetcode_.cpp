class Solution {
public:
    int min(int x, int y)
    {
        return (x<y) ? x:y;
    }
    int minDistance(string str1, string str2) 
    {
      int row =str1.length()+1;
      int col =str2.length()+1;
        
        vector<vector<int> > dp(row, vector<int> (col,-1));
        
    // when we have one string empty then edit dis. will be equal to the number of characters
    // in second string because we can just perform insert or delete  operations 
        
        for(int i=0; i<dp.size(); i++)
            dp[i][0] =i;
        for(int i=0; i<dp[0].size(); i++)
            dp[0][i]=i;
        
        for(int i=1; i<dp.size(); i++)
        {
            for(int j=1; j<dp[0].size(); j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1];      // if strings match then do nothing 
                else
                {
                    int insert = dp[i-1][j];
                    int replace =dp[i-1][j-1];
                    int del =dp[i][j-1];
                    
                    int res=min(insert, min(replace,del) );  
                    dp[i][j] = 1+ res;   //  plus one because we actually did one operation
                }
            }
        }
        
        return dp[row-1][col-1];
    }
};

/*  Time Complexity  : O(n*m), where n and m are length of str1 and str2 respectively
   Space Complexity  : O(n*m), because we need a (n x m)  matrix or a dp table to store our precomputations.
*/
