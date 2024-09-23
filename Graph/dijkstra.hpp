#pragma once

#include "Graph/graph-template.cpp"

//dijkstra
struct dijkstra{
    vector<long long> dist;
    vector<long long> prev;

    //dijkstraを構築
    dijkstra(Graph &G, long long s){
        long long N = G.size();
        dist.assign(N, 1LL << 60);
        prev.assign(N, -1);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        dist[s] = 0LL;
        pq.emplace(dist[s], s);
        while (!pq.empty()){
            auto p = pq.top();
            pq.pop();
            long long v = p.second;
            if(dist[v] < p.first) continue;
            for (auto &e : G[v]){
                if (dist[e.to] > dist[v] + e.cost){
                    dist[e.to] = dist[v] + e.cost;
                    prev[e.to] = v;
                    pq.emplace(dist[e.to], e.to);
                }
            }
        }
    }

    //最小コストを求める
    long long cost(ll to){
        return dist[to];
    }

    //最短経路を求める
    vector<long long> path(long long to){
        vector<ll> get_path;
        for (long long i = to; i != -1; i = prev[i]){
            get_path.push_back(i);
        }
        reverse(get_path.begin(), get_path.end());
        return get_path;
    }

    //到達可能か調べる
    bool cango(ll to){
        return dist[to] != 1LL << 60;
    }
};
