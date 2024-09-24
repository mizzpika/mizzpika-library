#pragma once

#include "Graph/graph-template.hpp"

//LCA
struct LCA {
    vector<vector<long long>> parent;
    vector<long long> dist;

    LCA(Graph &g, long long root = 0){
        vector<vector<Edge3>> G(g.size());
        for(long long i = 0; i < g.size(); i++){
            for(auto e : g[i]){
                G[i].emplace_back(e.to);
            }
        }
        long long V = G.size();
        long long K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<long long>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (long long k = 0; k + 1 < K; k++) {
            for (long long v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    void dfs(const vector<vector<Edge3>> &G, long long v, long long p, long long d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e.to != p) dfs(G, e.to, v, d + 1);
        }
    }

    //最小共通祖先を求める
    long long query(long long u, long long v) {
        if (dist[u] < dist[v]) swap(u, v);
        long long K = parent.size();
        for (long long k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        if (u == v) return u;
        for (long long k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    //最短距離を求める
    long long get_dist(long long u, long long v){
        return dist[u] + dist[v] - 2 * dist[query(u, v)];
    }

    //aがuとvのpath上にあるか
    bool is_on_path(long long u, long long v, long long a){
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
    }
};
