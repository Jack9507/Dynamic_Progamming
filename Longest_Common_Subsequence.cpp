#include<bits/stdc++.h>
using namespace std;
#define endl '\n'



//Time Complexity :   Simple recursive will have O(2^n)
// But memoization will reduce the complexity and iterative dp solution will be best with O(m*n) time complexity.
int helper(string str1, int pt1, string str2, int pt2, vector<vector<int> > &dp)
    {
        if(pt1 == str1.length() || pt2==str2.length())
        {
            dp[pt1][pt2]= 0;
            return 0;
        }

        if(dp[pt1][pt2] != -1)
            return dp[pt1][pt2];


        int res;
        if(str1[pt1] == str2[pt2])
        {
            res= 1 +  helper(str1, pt1+1, str2 ,pt2+1, dp);
        }
        else
        {
            int first =helper(str1, pt1+1, str2, pt2, dp);
            int second =helper(str1, pt1, str2, pt2+1, dp);
            res =max(first, second);
        }
        dp[pt1][pt2]=res;
      /*  for(int i=0; i<dp.size(); i++)
        {
            for(int j=0; j<dp[0].size(); j++)
                cout<<dp[i][j]<<'\t';
            cout<<endl;
        }
        cout<<endl<<"****************************************************************"<<endl;*/
        return res;
    }

int longestCommonSubsequence(string str1, string str2)
    {
        int row=str1.length()+1;
        int col=str2.length()+1;

        vector<vector<int> > dp(row, vector<int> (col, -1));
        return helper(str1, 0, str2, 0, dp);
    }


/*
Worst case time complexity: O(n*m)
Average case time complexity: O(n*m)
Best case time complexity: O(n*m)
Space complexity: O(n*m)
*/
int lcsfulldp(string str1, string str2)
    {
        int row= str1.length()+1;
        int col =str2.length()+1;

        vector<vector<int> > dp(row, vector<int> (col,0));

        for(int i=str1.length()-1; i>=0; i--)
        {
            for(int j=str2.length()-1; j>=0; j--)
            {
                if(str1[i] ==str2[j])
                {
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                else
                {
                    int first= dp[i+1][j];
                    int second= dp[i][j+1];
                    int res= max(first, second);
                    dp[i][j] =res;
                }
            }
        }

    // code to print the sequence
    vector<char> ans;
    int i=0,j=0;
    while(i<str1.length() && j<str2.length())
    {
        if(str1[i]==str2[j])
        {
            ans.push_back(str1[i]);
            i++; j++;
        }
        else if(dp[i+1][j] > dp[i][j+1])
                 i++;
        else
            j++;
    }
    cout<<"Subsequence is :  ";
    for(auto x :ans)
        cout<<x<<" ";
     cout<<endl;
        return dp[0][0];
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1="opengenus";
    string s2="engineers";

    //cout << longestCommonSubsequence(s1, s2) <<endl;
    cout << lcsfulldp(s1, s2) <<endl;





    return 0;
}

