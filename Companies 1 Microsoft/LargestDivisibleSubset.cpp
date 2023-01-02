//Variation of LIS
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(nums.size(), 0);
        vector<int>prev(nums.size(), 0);
        int maxLen=0;
        int maxIdx=0;
        for(int i=n-1; i>=0; --i){
            for(int j=i; j<n; ++j){
                if(nums[j]%nums[i]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                    if(dp[i]>maxLen){
                        maxLen=dp[i];
                        maxIdx=i;
                    }
                }
            }
        }
        vector<int>ans(maxLen);
        for(int i=0; i<maxLen; ++i){
            ans[i]=nums[maxIdx];
            maxIdx=prev[maxIdx];
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>ans=s.largestDivisibleSubset({1, 2, 4, 8});
    cout<<"[";
    for(auto &x: ans){
        cout<<x<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}