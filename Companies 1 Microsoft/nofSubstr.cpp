// Based on sliding window, idea to record last occuring of each each character and add to ans the earlist occurrance
#include <bits/stdc++.h>
using namespace std;
// Return ans as cost to open the gate + ans (if not traveled before)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(), ans=0;
        vector<int>lastCnt(3, -1);
        for(int i=0; i<n; ++i){
            lastCnt[s[i]-'a']=i;
            ans+=1+min({lastCnt[0], lastCnt[1], lastCnt[2]});
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.numberOfSubstrings("abcabc")<<endl; //output 10
    return 0;
}