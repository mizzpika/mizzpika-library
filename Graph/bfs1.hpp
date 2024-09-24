#pragma once

#include "Graph/graph-template.hpp"

//bfs1(単一始点最短経路)
struct bfs1{
    vector<bool> visited;
    vector<long long> dist;
    vector<long long> parent;

    //bfs1(単一始点最短経路)を構築
    bfs1(Graph &g, long long s){
        long long n = g.size();
        visited.assign(n, false);
        dist.assign(n, -1);
        parent.assign(n, -1);
        visited[s] = true;
        dist[s] = 0;
        parent[s] = -1;
        queue<long long> que;
        que.push(s);
        while(!que.empty()){
            long long cur = que.front();
            que.pop();
            for(auto nxt : g[cur]){
                if(!visited[nxt.to]){
                    que.push(nxt.to);
                    visited[nxt.to] = true;
                    dist[nxt.to] = dist[cur] + 1;
                    parent[nxt.to] = cur;
                }
            }
        }
    }

    //最小コストを求める
    long long cost(long long to){
        return dist[to];
    }

    //最短経路を求める
    vector<long long> path(long long to){
        vector<long long> path;
        if(!visited[to]){
            return path;
        }
        for(long long i = to; i != -1; i = parent[i]){
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    //到達可能か調べる
    bool cango(long long to){
        return visited[to];
    }
};
