// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
// Return the max of all f(k's).
//Based on formula F(k-i)=f(k-i-1)+sum-n*nums[n-i];

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int> nums) {
        int n=nums.size();
        int ans=0;
        int sum=0;
        // vector<int>dp(n); //Not really needed 
        for(int i=0; i<n; ++i){
            sum+=nums[i];
            ans+=i*nums[i];
        }
        // dp[0]=ans;
        int maxAns=ans;
        for(int i=1; i<n; ++i){
            // dp[i]=dp[i-1]+sum-n*nums[n-i];
            // ans=max(ans, dp[i]);
            ans=ans+sum-n*nums[n-i];
            maxAns=max(maxAns, ans);
        }
        // return ans;
        return maxAns;
    }
};

int main(){
    Solution s;
    cout<<s.maxRotateFunction({4, 3, 2, 6})<<endl; //output 26
    return 0;
}