#include<bits/stdc++.h>
using namespace std;

int max(int x, int y)
    {
        return (x>y) ? x :y;
    }

/*
Recursive Approach plus Memoization
Time Complexity for recursive approach :  O(2^n);
Memoization solves the overlapping subproblem and reduces the complexity from exponential time solution to a polynomial time solution.
Space Complexity  : O(n^2);
*/
int helper(string &str, int low, int high, vector<vector<int>> &dp)
    {
        if(low > high)
        {
            dp[low][high]=0;
            return 0;
        }
        if(low ==high)
        {
            dp[low][high]=1;
            return 1;
        }


        if(dp[low][high] != -1)
            return dp[low][high];

        int res;
        if(str[low] == str[high])
        {
            res =  2 + helper(str, low+1, high-1, dp);
        }
        else
        {
            int first =helper(str, low+1, high, dp);
            int second= helper(str, low, high-1, dp);
            res =max(first, second);
        }

        return dp[low][high] = res;
    }
int longestPalindromeSubseq(string s)
    {
         if(s.length() ==0)   return 0;
         if(s.length() ==1)   return 1;

        int row=s.length();
        int col=s.length();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        int n=s.length();
        return helper(s, 0, n-1, dp);


    }

/* Full Dynamic Programming,  Iterative Approach  which is obviously faster than recursive solution
Time Complexity : O(n^2)
Space Complexity  :O(n*n);
*/
int longestPalindromeSubseq(string s)
    {
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;

        const int row= s.length();
        const int col =s.length();

        vector<vector<int>> dp(row, vector<int>(col,0));

        int n=s.length();
        for(int i=0; i<n; i++)
            dp[i][i]=1;

        for(int col =1; col <n; col++)
        {
            for(int row= col-1; row>=0; row--)
            {
                if(s[row] ==s[col])
                {
                    dp[row][col] = 2 + dp[row+1][col-1];
                }
                else
                {
                    int first =dp[row+1][col];
                    int second =dp[row][col-1];
                    dp[row][col] = max(first, second);
                }
            }
        }

        return dp[0][col-1];
    }


 /*   NOTE :  Longest Palindromic Subsequence of a string is Equivalent to the Longest Common Subsequence between that string and reverse of that string.
Complexity Same as that of longest common subsequence.
Time Complexity: O(N * M), where N and M is length of the first and second string respectively.
Auxiliary Space: (N * M)
*/
int LCS(string &s1, string &s2, int pt1, int pt2, vector<vector<int>> &dp)
    {
        if(pt1 == s1.length() || pt2 == s2.length())
        {
            dp[pt1][pt2] =0;
            return 0;
        }


        if(dp[pt1][pt2] != -1)
            return dp[pt1][pt2];

         int res=0;
        // include current character if both are equal
        if(s1[pt1] == s2[pt2])
            res = 1 + LCS(s1, s2, pt1+1, pt2+1, dp);
        else
        {
            // exclude and move forward
            int first = LCS(s1, s2, pt1+1, pt2, dp);
            int second = LCS(s1, s2, pt1, pt2+1, dp);
            res=max(first, second);
        }
        return dp[pt1][pt2] = res;
    }
int longestPalindromeSubseq(string str)
    {
        string tmp = str;
        reverse(tmp.begin(), tmp.end());
        int n=str.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return LCS(str,tmp,0,0, dp);
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

      cout<<longestPalindromeSubseq("bbbab")<<endl;


    return 0;
}
