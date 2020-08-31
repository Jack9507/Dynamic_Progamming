#include<bits/stdc++.h>
using namespace std;

int knapsack(int si, int wt[], int val[], int capacity, int n)
{
    if(si==n)         //base case
        return 0;

    int include =INT_MIN;

    if(wt[si] <= capacity)
    {
        include =val[si] + knapsack(si+1, wt, val, capacity-wt[si], n);
    }

    int skip =knapsack(si+1, wt, val, capacity, n);
    int result =max(include, skip);
    return result;

}

// number of variating parameters = 2 i.e. si and capacity so 2d array is required for memoization
int knapsack_memo(int si, int wt[], int val[], int capacity, int n, vector<vector<int> > &dp)
{
    if(si==n)  //base case
     {
         dp[si][capacity] =0;
         return 0;
     }

     if(dp[si][capacity] != -1)
        return dp[si][capacity];

    int include =INT_MIN;

    if(wt[si] <= capacity)
    {
        include =val[si] + knapsack_memo(si+1, wt, val, capacity-wt[si], n, dp);
    }

    int skip =knapsack_memo(si+1, wt, val, capacity, n,dp);
    int result =max(include, skip);

    dp[si][capacity]=result;
    cout<<endl;
      for(int i=0; i<dp.size(); i++)
      {
        for(int j=0; j<dp[0].size(); j++)
        {
            cout<<dp[i][j]<<'\t';
        }
        cout<<'\n';
      }
     cout<<endl<<"**********************************************************"<<endl;
    return result;

}

// iterative version
int knapsack_full_dp(int weight[], int value[], int capacity, int n)
{
    int row= n+1;
    int col= capacity+1;
    vector<vector<int> > dp(row, vector<int> (col,0));

    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<capacity; j++)
        {
            int include =INT_MIN;
            int exclude =INT_MIN;
            if(weight[i]  <= capacity)
              include= value[i] +dp[i+1][j - weight[i]];
            else
                exclude = dp[i+1][j];
         dp[i][j]=max(include, exclude);

        }
        return dp[0][capacity-1];

    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int weight[] = {5, 4, 6, 3};
	int value[] = {50, 40, 60, 40};
	int capacity = 8;
	int n = 4;


	// returns the maximum value which can be obtained within the bag capacity
	//cout<<knapsack(0, weight, value, capacity, n)<<endl;


	vector<vector<int> > dp(n+1, vector<int> (capacity+1, -1));
    cout<<knapsack_full_dp(weight, value, capacity, n)<<endl;


    return 0;
}
