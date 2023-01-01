// Evaluate Reverse Polish Notation
// 3+4 = 34+
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> tokens) {
        stack<string>sk;
        int ans=0;
        for(auto &it:tokens){
            if(it=="+" || it=="-" || it=="*" || it=="/"){
                int n1=stoi(sk.top());
                sk.pop();
                int n2=stoi(sk.top());
                sk.pop();
                if(it=="+")sk.push(to_string(n1+n2));
                else if(it=="-")sk.push(to_string(n2-n1));
                else if(it=="*")sk.push(to_string(n1*n2));
                else sk.push(to_string(n2/n1));
            }
            else sk.push(it);
        }
        ans=stoi(sk.top());
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.evalRPN({"2","1","+","3","*"})<<endl; //output 9
    return 0;
}