#include <bits/stdc++.h>

using namespace std;

#define PRINT         \
    cout << "PASS\n"; \
    else cout << "FAIL\n";

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int i, j, k, u, v, s;
        vector<vector<int>> graph(N, vector<int>());
        queue<int> q;
        // visited status
        vector<int> visited(N, 0);

        // convert into graph
        for(i = 0; i < dislikes.size(); i++){
            u = dislikes[i][0] - 1;
            v = dislikes[i][1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(i = 0; i < N; i++){

            // person is not grouped
            if(visited[i] != 0)
                continue;

            // add current person to queue
            q.push(i);
            // put person in first group
            visited[i] = 1;

            while(!q.empty()){

                // queue size
                s = q.size();
                for(j = 0; j < s; j++){
                    // get person from queue
                    u = q.front();
                    q.pop();

                    // check persons connections
                    for(k = 0; k < graph[u].size(); k++){
                        // get second person
                        v = graph[u][k];
                        // second person is not grouped
                        if(visited[v] == 0){
                            // add second preson to queue
                            q.push(v);
                            // decide group for second person based on first persons group
                            visited[v] = visited[u] == 1 ? 2 : 1;
                        }

                        // if both are in same group
                        if(visited[v] == visited[u])
                            return false;
                    }
                }
            }
        }
        return true;
        
    }
};


class Solution1 {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> mat(N + 1);

        // convert it into graph
        for (auto& v : dislikes)
        {
            mat[v[0]].push_back(v[1]);
            mat[v[1]].push_back(v[0]);
        }
        
        // make visited array
        vector<int> visited(N + 1);

        // check each person
        for (int i = 1; i <= N; ++i)
        {
            // if not visited
            if (!visited[i])
            {
                // check bipartition
                if (!isBipartition(visited, mat, i, true)) return false;
            }
        }
        return true;
        
    }
    

    static bool isBipartition(vector<int>& visited, const vector<vector<int>>& mat, int curr, bool isA)
    {
        // both are in same group
        if (isA && visited[curr] == 2) return false;
        if (!isA && visited[curr] == 1) return false;

        // if curr is already grouped
        if (visited[curr]) return true;
        
        // update visited array
        visited[curr] = isA ? 1 : 2;
        
        // check current person
        for (auto& next : mat[curr])
        {
            // recurse call
            if (!isBipartition(visited, mat, next, !isA)) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v;

    v = {{1,2},{1,3},{2,4}};

    if(s.possibleBipartition(4,v) == true) PRINT

    v = {{1,2},{1,3},{2,3}};
    if(s.possibleBipartition(3,v) == false) PRINT

    v = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
    if (s.possibleBipartition(5, v) == false) PRINT

    return 0;
}