class Solution {
public:
    int helper(string &str, string &tmp, int si, int ti, vector<vector<int>> &dp)
    {
        if(ti == tmp.length())
        {
            dp[si][ti]=1;
            return 1;
        }
        if(si == str.length() )
        {
            dp[si][ti]=0;
            return 0;
        }
        

        if(dp[si][ti] != -1)
            return dp[si][ti];
        
        int cnt_seq=0;
        if(str[si] == tmp[ti])
        {
            cnt_seq += helper(str, tmp, si+1, ti+1, dp);
        }
        
            cnt_seq +=helper(str, tmp ,si+1, ti, dp);
        
        return dp[si][ti]=cnt_seq;
    }
    int numDistinct(string str, string tmp) 
    {
        if(str.length() == 0 )
        {
            return 0;
        }
        if(tmp.length() == 0)
        {
            return 1;
        }
        
        
        vector<vector<int>> dp(str.length()+1,vector<int>(tmp.length()+1,-1));
          return helper(str, tmp, 0, 0, dp);
        
    }
};
