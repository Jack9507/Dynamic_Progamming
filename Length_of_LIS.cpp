#include<bits/stdc++.h>
using namespace std;
#define mod 1e9
#define int long long
#define endl '\n'


// Recursive Solution
// TIme Complexity  :  O(2^n);
int LIS(vector<int> &nums, int prev, int curr)
{
    if(curr==nums.size())
        return 0;

    int include =0;      // initially length of subsequence is 0.

    if(nums[curr] > prev)
    {
        include = 1 + LIS(nums, nums[curr], curr+1);       // if we include the curr element then ans becomes 1 + length of subsequence from curr +1
    }
    int exclude =LIS(nums, prev, curr+1);          // if we exclude the curr element then prev stays the same because no element is added in subsequence

    return max(include, exclude);

}


// DP solution
// Time Complexity  : O(n^2)
int LIS_dp(vector<int> &nums)
{
    int n =nums.size();
    vector<int> dp(n,1);      //  initially  every element can from a subsequence of 1 length so fill the entire array with '1'.

    int maxlen =1;

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] +1);
            }
        }
        maxlen =max(maxlen, dp[i]);
    }

    return maxlen;
}



// The best solution to find LIS is in O(nlogn) time complexity :
// It uses
int LIS_n_log_n(vector<int> &nums)
{
    vector<int> res;
    res.push_back(nums[0]);  //  res array stores the subsequence so far

    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i] > res.back())
            res.push_back(nums[i]);
        else
        {
            int lb= lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
            res[lb]=nums[i];
        }
    }

    for(auto x: res)
        cout<<x<<" ";
    cout<<endl;

    return res.size();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums ={10,9,2,5,3,7,101,18};

    int prev=INT_MIN;

    //recursive_solution
    cout<<LIS(nums, prev, 0)<<endl;

    // dynamic programming_solution
    cout<<LIS_dp(nums)<<endl;


    // O(nlog(n) solution
    cout<<LIS_n_log_n(nums)<<endl;


    return 0;
}
