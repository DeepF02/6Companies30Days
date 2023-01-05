// Based on 2 pointer Algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> nums) {
        int i=0, j=nums.size()-1;
        int curMax=1e5+1, curMin=-1e5-1;
        int start=0, end=-1;
        while(j>=0){
            if(curMin<=nums[i])curMin=nums[i];
            else end=i;
            if(curMax>=nums[j])curMax=nums[j];
            else start=j;
            ++i,--j;
        }
        return end-start+1;
    }
};

int main(){
    Solution s;
    cout<<s.findUnsortedSubarray({4, 3, 2, 6})<<endl; //output 3
    return 0;
}