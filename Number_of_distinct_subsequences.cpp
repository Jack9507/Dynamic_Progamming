#include<bits/stdc++.h>
using namespace std;


/*
Time Complexity : O(2^n)
Space Complexity  :O(n)
*/
unordered_set<string> s1;
void recursive_approach(string str, string ans)
{
    if(str.length() == 0)
    {
        cout<<ans<<endl;
        s1.insert(ans);
        return;
    }

    char ch=str[0];
    string ros =str.substr(1);

    recursive_approach(ros, ans+ch);
    recursive_approach(ros, ans);

}



/* Dynamic Programming approach
Time Complexity :  O(n)
Space Complexity  : O(n)
*/

const int mod = 1e9+7;
int distinctSubseqII(string str)
    {
        int n =str.size();
        vector<int> dp(n+1, 0);   // stored subsequences till index i
        vector<int> last(26, -1);      // stores the index of prev occurence of character

        dp[0]=1;         // initially if string has length =0 then it will have one empty subsequence

        for(int i=0; i<n; i++)     // iterating from index 0  to n-1
        {
            int x=str[i]-'a';
            dp[i+1] = 2 * dp[i];
               if(dp[i+1] >mod) dp[i+1] %= mod;     // avoids overflow

            if(last[x] >=0)    // if the current char has appeared previously
            {
               dp[i+1] -= dp[last[x]];         // subtract the sequences which has been counted twice
              if(dp[i+1] <0) dp[i+1]+=mod;
            }
            last[x] =i;               // store the index of current character
        }

        dp[n]--;     // eleminate ""  empty subsequene
        if(dp[n] < 0)
            dp[n]+=mod;
        return dp[n];
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string str ="abab";
    cout<<str<<endl;


    recursive_approach(str, "");
   cout<<"Distinct Count of Subsequences = "<<s1.size()<<endl;


    cout<<endl;

     cout<<"Dynamic Programming Approach "<<endl;
     cout<<"Count of distinct subsequences without the null subsequence =";
    cout<<distinctSubseqII(str);
    cout<<endl;




    return 0;
}
