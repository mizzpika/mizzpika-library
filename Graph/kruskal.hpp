#pragma once

#include "Graph/graph-template.hpp"

#include "Graph/DSU.hpp"

//kruskal
struct kruskal{
    long long n;
    vector<Edge2> edges;
    //kruskalの構築
    kruskal(Graph &g){
        n = g.size();
        for(long long i = 0; i < n; i++){
            for(auto e : g[i]){
                edges.emplace_back(i, e.to, e.cost);
            }
        }
    }

    //最小全域木のコストを求める
    long long mincost(){
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        long long ret = 0;
        for(auto e : edges){
            if(dsu.merge(e.from, e.to))ret += e.cost;
        }
        return ret;
    }

    //最大全域木のコストを求める
    long long maxcost(){
        sort(edges.rbegin(), edges.rend());
        DSU dsu(n);
        long long ret = 0;
        for(auto e : edges){
            if(dsu.merge(e.from, e.to))ret += e.cost;
        }
        return ret;
    }
};