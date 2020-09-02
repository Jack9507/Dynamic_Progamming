#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


/*
Brute Force Solution
Time Complexity : O(n^3)
Space Complexity  :O(1)
*/
bool ispalindrome(string str)
    {
        string tmp =str;

        reverse(tmp.begin(), tmp.end());

        return tmp == str;
    }
string longestPalindrome_recursive(string str)
    {
        int n=str.length();

        string ans;

        for(int i=0; i<n; i++)
        {
            for(int len=1; len <= n-i; len++)
            {
                string ros =str.substr(i, len);
                if(ispalindrome(ros))
                {
                    if(ros.length() > ans.length())
                    {
                        ans= ros;
                    }
                }

            }
        }

        return ans;
    }




// Dynamic Programming solution
// Time Complexity : O(n^2)
// Space Complexity : O(n^2)
string longestPalindrome(string str)
    {
          int n=str.length();
        if(n == 0) return "";
        if(n==1)   return str;

        vector<vector<bool> > dp(n,vector<bool>(n,0));
        //  filing diagonal elements i.e 1 length string
        for(int i=0; i<n; i++)
        {
            dp[i][i]=1;
        }
        // fling dp table for 2 length string
        for(int i=0; i<n-1; i++)
        {
            if(str[i]==str[i+1])
                dp[i][i+1]=1;
        }

        for(int i=n-3; i>=0; i--)           // start from bottom row because to fill the above rows you may need the below rows.
        {
            for(int j=i+2; j<n; j++)
            {
                if(str[i] == str[j])
                {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
        }

        // extract the length of max substring and the actual substring
        int maxlen=0;
         string res="";

         for(int i=0; i<n; i++)
         {
             for(int j=i; j<n; j++)
             {
                 if(dp[i][j]==1 && j-i+1 > maxlen)
                 {
                         maxlen = j-i+1;
                         res= str.substr(i, j-i+1);
                 }
             }
         }

          return res;
    }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        string str="babad";

        cout<<longestPalindrome_recursive(str);
        cout<<endl;
        cout<<longestPalindrome(str);


     return 0;
}

