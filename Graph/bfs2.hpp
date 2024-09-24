#pragma once

#include "Graph/graph-template.hpp"

//bfs2(全点対最短経路)
struct bfs2{
    vector<vector<bool>> visited;
    vector<vector<long long>> dist;
    vector<vector<long long>> parent;
    bfs2(Graph &g){
        long long n = g.size();
        visited.assign(n, vector<bool>(n, false));
        dist.assign(n, vector<long long>(n, -1));
        parent.assign(n, vector<long long>(n, -1));
        for(long long s = 0; s < n; s++){
            visited[s][s] = true;
            dist[s][s] = 0;
            parent[0][0] = -1;
            queue<long long> que;
            que.push(s);
            while(!que.empty()){
                long long cur = que.front();
                que.pop();
                for(auto nxt : g[cur]){
                    if(!visited[s][nxt.to]){
                        que.push(nxt.to);
                        visited[s][nxt.to] = true;
                        dist[s][nxt.to] = dist[s][cur] + 1;
                        parent[s][nxt.to] = cur;
                    }
                }
            }
        }
    }

    //最小コストを求める
    long long cost(long long from, long long to){
        return dist[from][to];
    }

    //最短経路を求める
    vector<long long> path(long long from, long long to){
        vector<long long> path;
        if(!visited[from][to]){
            return path;
        }
        for(long long i = to; i != -1; i = parent[from][i]){
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    //到達可能か調べる
    bool cango(long long from, long long to){
        return visited[from][to];
    }
};
