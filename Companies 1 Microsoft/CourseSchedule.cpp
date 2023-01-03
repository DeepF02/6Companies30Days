// must take course b first to take course a. i.e b->a edge of node b and a in graph representation
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    //DFS Topological Sort to deetct cycle;
    bool topologicalSort(vector<int>adj[], int node, vector<int>&visited){
        if(visited[node]==1)return false; //Means current node's child node are being visited
        if(!visited[node]){ // Node not visted yet
            visited[node]=1;
            for(auto &it:adj[node])if(!topologicalSort(adj, it, visited))return false;
        }
        visited[node]=2; //Node being visited completely
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
        //Using topological to find cycles causes if cycle exists we can't finish any course cause of loop
        vector<int>adj[numCourses];
        for(auto &it:prerequisites)adj[it[1]].push_back(it[0]);
        vector<int>visited(numCourses, 0);
        for(int i=0; i<numCourses; ++i)if(!topologicalSort(adj, i, visited))return false;
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.canFinish(2, {{1,0}})<<endl; //output true
    return 0;
}