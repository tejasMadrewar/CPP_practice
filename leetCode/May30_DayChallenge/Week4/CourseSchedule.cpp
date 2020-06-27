#include<bits/stdc++.h>

using namespace std;
#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

//There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

class Solution {
public:

    bool isCycle(vector<int> adj[], vector<int> &vis,int id){
        if(vis[id] == 1) return true;

        if(vis[id] == 0){
            vis[id] =1;
            for(auto edge:adj[id]){
                if(isCycle(adj,vis,edge))
                    return true;
            }

        }

        vis[id] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> vis(numCourses,0);

        // convert it to graph
        for(auto edge:prerequisites)
            adj[edge[1]].push_back(edge[0]);

        for(int i=0; i <numCourses; i++){
            if(isCycle(adj,vis,i))
                return false;
        }

        return true;
    }
};

class Solution1 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegrees(numCourses);
        
        for(auto& p : prerequisites) {
            adjList[p[1]].push_back(p[0]);
            ++inDegrees[p[0]];
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(inDegrees[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            --numCourses;
            
            for(auto& next : adjList[current]) {
                if(--inDegrees[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return numCourses == 0;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> v;

    v = {{1, 0}};
    if (s.canFinish(2, v) == true)
        PRINT

    v = {{1, 0}, {0, 1}};
    if (s.canFinish(2, v) == false)
        PRINT
}