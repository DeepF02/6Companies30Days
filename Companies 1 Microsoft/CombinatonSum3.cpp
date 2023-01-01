//Same as Combination Sum 1&2 just apply 0/1 knapsack instead of unbounded knapsack
// Use Backtracking
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void solve(vector<vector<int>>& ans, vector<int>& combination, int k, int n){
        if(n<0)return;
        if(combination.size()==k){
            if(n==0)ans.push_back(combination);
            return;
        }
        for(int i=combination.empty()?1:combination.back()+1; i<10; ++i){
            combination.push_back(i);
            solve(ans, combination, k, n-i);
            combination.pop_back(); // Backtrack
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>combination;
        solve(ans, combination, k, n);
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>>ans=s.combinationSum3(3, 9);
    for(auto &it:ans){
        cout<<"[ ";
        for(auto &x: it){
            cout<<x<<" ";
        }
        cout<<"] ";
    }
    cout<<endl;
    return 0;
}