//This code is giving TLE for now will update later with opimised solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // All the given rectangles should satisfy this 3 cnd to foram an exact cover of an rect area
        
        // Cnd 1 : None of the rectanle must overlap
        int n =rectangles.size();
        if(n==1)return true;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(rectangles[i][0]<rectangles[j][2] && rectangles[j][0]<rectangles[i][2] && rectangles[i][1]< rectangles[j][3] && rectangles[j][1]<rectangles[i][3]) return 0;
            }
        }

        // Cnd 2 : Rectangles form a contiguous area i.e all the rectanglesa are adjacent to prev processed rectangles
        // vector<bool> processed(rectangles.size(), false);
        // for (int i = 0; i <n; ++i) {
        //     bool found = 0;
        //     for (int j = 0; j <n; ++j) {
        //         if(i==j)continue;
        //         if ((rectangles[i][0] == rectangles[j][2] && rectangles[i][1] < rectangles[j][3] && rectangles[j][1] < rectangles[i][3]) || (rectangles[i][2] == rectangles[j][0] && rectangles[i][1] < rectangles[j][3] && rectangles[j][1] < rectangles[i][3]) || (rectangles[i][1] == rectangles[j][3] && rectangles[i][0] < rectangles[j][2] && rectangles[j][0] < rectangles[i][2]) || (rectangles[i][3] == rectangles[j][1] && rectangles[i][0] < rectangles[j][2] && rectangles[j][0] < rectangles[i][2])){
        //             processed[i] = 1;
        //             found = 1;
        //             break;
        //         }
        //     }
        //     if(!found)return 0;
        // }

        // Cnd 3 : Rectangles form an exact covert i.e r1+r2+..rn=Area(covert rectangle)
        int xmin=INT_MAX;
        int ymin=INT_MAX;
        int xmax=INT_MIN;
        int ymax=INT_MIN;
        int allAreas = 0;
        for(auto &it:rectangles){
            xmin=min(xmin, it[0]);
            ymin=min(ymin, it[1]);
            xmax=max(xmax, it[2]);
            ymax=max(ymax, it[3]);
            allAreas+=(it[2]-it[0])*(it[3]-it[1]);
        }
        int totalArea = (xmax-xmin)*(ymax-ymin);
        if(totalArea!=allAreas) return false;

        // vector<vector<int>> grid(ymax - ymin, vector<int>(xmax - xmin, 0));
        // for (const vector<int>& rectangle : rectangles) {
        //     for (int i = rectangle[1] - ymin; i < rectangle[3] - ymin; i++) {
        //         for (int j = rectangle[0] - xmin; j < rectangle[2] - xmin; j++) {
        //             if (++grid[i][j] > 1) return false;
        //         }
        //     }
        // }

        return true;
    }
};

int main(){
    Solution s;
    vector<vector<int>>rectangles={{4, 3, 2, 6}};
    cout<<s.isRectangleCover(rectangles)<<endl; //output 
    return 0;
}