#pragma once

#include "Graph/graph-template.hpp"

//bellman_ford
struct bellman_ford{
    vector<long long> dist;
    vector<long long> prev;
    long long start;
    long long n;
    bool cl = false;

    //bellman_fordを構築
    bellman_ford(Graph &g, long long s){
        start = s;
        n = g.size();
        dist.assign(n, 1LL << 60);
        prev.assign(n, -1);
        vector<long long> counts(n);
        vector<bool> inqueue(n);

        queue<long long> q;
        dist[s] = 0;
        q.push(s);
        inqueue[s] = true;

        while(!q.empty()){
            long long from = q.front();
            q.pop();
            inqueue[from] = false;

            for(auto &e : g[from]){
                long long d = dist[from] + e.cost;
                if(d < dist[e.to]){
                    dist[e.to] = d;
                    prev[e.to] = from;
                    if(!inqueue[e.to]){
                        q.push(e.to);
                        inqueue[e.to] = true;
                        ++counts[e.to];

                        if(n < counts[e.to])cl = true;
                    }
                }
            }
        }
    }

    //最小コストを求める
    long long get_cost(long long to){
        return dist[to];
    }

    //最短経路を求める
    vector<long long> get_path(long long to){
        vector<long long> path;
        if(dist[to] != 1LL << 60){
            for(long long i = to; i != -1; i = prev[i]){
                path.push_back(i);
            }
            reverse(path.begin(), path.end());
        }
        return path;
    }

    //到達可能か調べる
    bool cango(long long to){
        return (dist[to] != 1LL << 60);
    }

    //負の閉路の有無を調べる
    bool closed(){
        return cl;
    }
};
