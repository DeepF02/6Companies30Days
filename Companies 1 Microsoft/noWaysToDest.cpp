// Based on dijkstra's algo to find shortest path
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>

class Solution {
private:
    ll dijkstra(int n, vector<pll> adj[]){ 
        ll cnt=0, mod=1000000007;
        vector<ll>dist(n, LONG_MAX), ways(n);
        priority_queue<pll>minHeap; 
        dist[0]=0;
        ways[0]=1;
        minHeap.push({0, 0}); //distn, node
        while(!minHeap.empty()){
            auto currDist = -minHeap.top().first, currNode = minHeap.top().second;
            minHeap.pop();
            if(currDist>dist[currNode])continue;
            for(auto [v, nextDist]:adj[currNode]){
                if(dist[v]==currDist + nextDist) ways[v]=(ways[v]+ways[currNode])%mod;
                else if(dist[v]>currDist + nextDist){
                    ways[v]=ways[currNode];
                    dist[v]=currDist + nextDist;
                    minHeap.push({-dist[v], v});
                }
            }
        }
        return ways[n-1];
    }

public:
    int countPaths(int n, vector<vector<int>> roads) {
        vector<pll>adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        return dijkstra(n, adj);
    }
};

int main(){
    Solution s;
    cout<<s.countPaths(2, {{1,0,10}})<<endl; //output 1
    return 0;
}