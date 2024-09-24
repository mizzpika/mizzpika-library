#pragma once

#include "Graph/graph-template.hpp"

//warshall_floyd
struct warshall_floyd{
    vector<vector<long long>> d;
    vector<vector<long long>> next;
    bool cl = false;

    //warshall_floydを構築
    warshall_floyd(Graph &g){
        long long n = g.size();
        d.resize(n, vector<long long>(n, 1long long << 60));
        next.resize(n, vector<long long>(n, -1));

        for(long long i = 0; i < n; i++){
            d[i][i] = 0;
        }

        for(long long i = 0; i < n; i++){
            for(auto e : g[i]){
                d[i][e.to] = e.cost;
                next[i][e.to] = e.to;
            }
        }

        for(long long k = 0; k < n; ++k){
            for(long long i = 0; i < n; ++i){
                for(long long j = 0; j < n; ++j){
                    if(d[i][k] == 1LL << 60 || d[k][j] == 1LL << 60)continue;
                    if(d[i][j] > d[i][k] + d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }

        for(long long i = 0; i < n; i++){
            if(d[i][i] < 0){
                cl = true;
                break;
            }
        }
    }

    //最小コストを求める
    long long cost(long long from, long long to){
        return d[from][to];
    }

    //最短経路を求める
    vector<long long> path(long long from, long long to) {
        if (d[from][to] == 1LL << 60) return {};
        vector<long long> path;
        for(long long at = from; at != to; at = next[at][to]){
            if (at == -1) return {};
            path.push_back(at);
        }
        path.push_back(to);
        return path;
    }

    //到達可能か調べる
    bool cango(long long from, long long to){
        return d[from][to] != 1LL << 60;
    }

    //負の閉路の有無を調べる
    bool closed(){
        return cl;
    }
};
