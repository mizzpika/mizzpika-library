#pragma once

#include "Graph/graph-template.hpp"

#include "Graph/DSU.hpp"

//kruskal
struct kruskal{
    long long n;
    vector<Edge2> edges;
    bool mn_finish = false, mx_finish = false;
    long long mn, mx;
    set<long long> mn_path, mx_path;
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
    long long min_cost(){
        if(mn_finish){
            return mn;
        }
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        long long ret = 0;
        for(auto e : edges){
            if(dsu.merge(e.from, e.to)){
                ret += e.cost;
                mn_path.insert(e.from);
                mn_path.insert(e.to);
            }
        }
        return mn = ret;
    }

    //最大全域木のコストを求める
    long long max_cost(){
        if(mx_finish){
            return mx;
        }
        sort(edges.rbegin(), edges.rend());
        DSU dsu(n);
        long long ret = 0;
        for(auto e : edges){
            if(dsu.merge(e.from, e.to)){
                ret += e.cost;
                mx_path.insert(e.from);
                mx_path.insert(e.to);
            }
        }
        return mx = ret;
    }

    //最小全域木のパスをsetで求める
    set<long long> min_path(){
        if(mn_finish){
            return mn_path;
        }
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        long long ret = 0;
        for(auto e : edges){
            if(dsu.merge(e.from, e.to)){
                ret += e.cost;
                mn_path.insert(e.from);
                mn_path.insert(e.to);
            }
        }
        return mn_path;
    }

    //最大全域木のパスをsetで求める
    set<long long> max_path(){
        if(mx_finish){
            return mx_path;
        }
        sort(edges.rbegin(), edges.rend());
        DSU dsu(n);
        long long ret = 0;
        for(auto e : edges){
            if(dsu.merge(e.from, e.to)){
                ret += e.cost;
                mx_path.insert(e.from);
                mx_path.insert(e.to);
            }
        }
        return mx_path;
    }
};
